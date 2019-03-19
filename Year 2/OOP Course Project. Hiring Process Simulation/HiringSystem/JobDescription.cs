// File:    JobDescription.cs
// Author:  Михайло
// Created: 1 октября 2018 г. 18:48:47
// Purpose: Definition of Class JobDescription

using System;

namespace HiringSystem
{
    /// <summary>
    /// Клас опису вакансії.
    /// </summary>
    public class JobDescription
    {
        ///позиція, на яку шукається людина
        private string position;
        public string Position
        {
            get
            {
                return position;
            }
            set
            {
                position = value;
            }
        }
        ///необхідний вчений ступінь
        private string degree;
        public string Degree
        {
            get
            {
                return degree;
            }
            set
            {
                degree = value;
            }
        }
        ///необхідна кількість років досвіду
        private int experience;
        public int Experience
        {
            get
            {
                return experience;
            }
            set
            {
                try
                {
                    if (value < 0)//при встановлення від'ємного значення необхідної кількості років досвіду
                    {
                        throw new Error(2);//викликати обробник помилок
                    }
                    experience = value;
                }
                catch (Error e)
                {
                    e.err();//обробити помилку
                }
            }
        }
        ///необхідний рівень навичок
        private string skill_level;
        public string Skill_level
        {
            get
            {
                return skill_level;
            }
            set
            {
                skill_level = value;
            }
        }
        ///необхідні технології, якими має володіє кандидат
        private string technologies;
        public string Technologies
        {
            get
            {
                return technologies;
            }
            set
            {
                technologies = value;
            }
        }
        ///необхідні особисті якості
        private string personal_qualities;
        public string Personal_qualities
        {
            get
            {
                return personal_qualities;
            }
            set
            {
                personal_qualities = value;
            }
        }
        ///зарплатня
        private float wage;
        public float Wage
        {
            get
            {
                return wage;
            }
            set
            {
                try
                {
                    if (value < 0)//при встановлення від'ємного значення необхідної кількості років досвіду
                    {
                        throw new Error(1);//викликати обробник помилок
                    }
                    wage = value;
                }
                catch (Error e)
                {
                    e.err();//обробити помилку
                }
            }
        }

        /// <summary>
        /// Перевантаження оператору додавання: додавання зарплатні об'єктів опису вакансії
        /// </summary>
        public static JobDescription operator +(JobDescription jd1, JobDescription jd2)
        {
            return new JobDescription(jd1.position, jd1.skill_level, jd1.degree, jd1.experience, jd1.technologies, jd1.personal_qualities, jd1.wage + jd2.wage);
        }

        /// <summary>
        /// Перевантаження оператору віднімання: віднімання зарплатні об'єктів опису вакансії
        /// </summary>
        public static JobDescription operator -(JobDescription jd1, JobDescription jd2)
        {
            float wg;
            if (jd1.wage - jd2.wage < 0) //попередження від'ємного значення зарплатні
            {
                wg = 0;
            }
            else
            {
                wg = jd1.wage - jd2.wage;
            }
            return new JobDescription(jd1.position, jd1.skill_level, jd1.degree, jd1.experience, jd1.technologies, jd1.personal_qualities, wg);
        }
        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public JobDescription()
        {
            position = "";//інціалізація рядку позиції, на яку шукається людина
            skill_level = "";//ініціалізація рядку рівня навичок
            degree = "";//ініціалізація рядку вченої степені
            experience = 0;//ініціалізація кількості років досвіду
            technologies = "";//ініціалізація рядку технологій, якими володіє
            personal_qualities = "";//ініціалізація рядку особистих якостей
            wage = 0;// ініціалізація зарплатні
        }

        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public JobDescription(string pos, string skill, string deg, int exp, string tech, string persqual, float wg)
        {
            position = pos;//інціалізація рядку позиції, на яку шукається людина
            skill_level = skill;//ініціалізація рядку рівня навичок
            degree = deg;//ініціалізація рядку вченої степені
            experience = exp;//ініціалізація кількості років досвіду
            technologies = tech;//ініціалізація рядку технологій, якими володіє
            personal_qualities = persqual;//ініціалізація рядку особистих якостей
            wage = wg;// ініціалізація зарплатні
        }

        /// <summary>
        /// Конструктор за копії.
        /// </summary>
        public JobDescription(JobDescription jd)
        {
            position = jd.position;//інціалізація рядку позиції, на яку шукається людина
            skill_level = jd.skill_level;//ініціалізація рядку рівня навичок
            degree = jd.degree;//ініціалізація рядку вченої степені
            experience = jd.experience;//ініціалізація кількості років досвіду
            technologies = jd.technologies;//ініціалізація рядку технологій, якими володіє
            personal_qualities = jd.personal_qualities;//ініціалізація рядку особистих якостей
            wage = jd.wage;// ініціалізація зарплатні
        }

        /// <summary>
        /// Конструктор за перетворення.
        /// </summary>
        public JobDescription(double exp)
        {
            position = "";//інціалізація рядку позиції, на яку шукається людина
            skill_level = "";//ініціалізація рядку рівня навичок
            degree = "";//ініціалізація рядку вченої степені
            experience = (int)exp;//ініціалізація кількості років досвіду
            technologies = "";//ініціалізація рядку технологій, якими володіє
            personal_qualities = "";//ініціалізація рядку особистих якостей
            wage = 0;// ініціалізація зарплатні
        }
        /// <summary>
        /// Деструктор
        /// </summary>
        ~JobDescription()
        {
        }
    }
}