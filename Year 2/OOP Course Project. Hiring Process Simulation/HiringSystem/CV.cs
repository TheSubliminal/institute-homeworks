// File:    CV.cs
// Author:  Михайло
// Created: 30 сентября 2018 г. 18:53:49
// Purpose: Definition of Class CV

using System;

namespace HiringSystem
{
    /// <summary>
    /// Клас резюме подавача заявки на роботу.
    /// </summary>
    public class CV
    {
        ///вчений ступінь
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
        ///кількість років досвіду
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
                    if (value < 0)//при встановлення від'ємного значення кількості років досвіду
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
        ///рівень навичок
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
        ///технології, якими володіє
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
        ///особисті якості
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

        /// <summary>
        /// Перевантаження оператору інкременту, який інкрементує кількість років досвіду
        /// </summary>
        public static CV operator ++(CV cv)
        {
            cv.experience++;
            return cv;
        }
        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public CV()
        {
            degree = "";//ініціалізація рядку вченої степені
            experience = 0;//ініціалізація кількості років досвіду
            skill_level = "";//ініціалізація рядку рівня навичок
            technologies = "";//ініціалізація рядку технологій, якими володіє
            personal_qualities = "";//ініціалізація рядку особистих якостей
        }

        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public CV(string degr, int exp, string skill, string tech, string persqual)
        {
            degree = degr;//ініціалізація рядку вченої степені
            experience = exp;//ініціалізація кількості років досвіду
            skill_level = skill;//ініціалізація рядку рівня навичок
            technologies = tech;//ініціалізація рядку технологій, якими володіє
            personal_qualities = persqual;//ініціалізація рядку особистих якостей
        }

        /// <summary>
        /// Конструктор копії.
        /// </summary>
        public CV(CV cv)
        {
            degree = cv.degree;//ініціалізація рядку вченої степені
            experience = cv.experience;//ініціалізація кількості років досвіду
            skill_level = cv.skill_level;//ініціалізація рядку рівня навичок
            technologies = cv.technologies;//ініціалізація рядку технологій, якими володіє
            personal_qualities = cv.personal_qualities;//ініціалізація рядку особистих якостей
        }

        /// <summary>
        /// Конструктор перетворення.
        /// </summary>
        public CV(double exp)
        {
            degree = "";//ініціалізація рядку вченої степені
            experience = (int)exp;//ініціалізація кількості років досвіду
            skill_level = "";//ініціалізація рядку рівня навичок
            technologies = "";//ініціалізація рядку технологій, якими володіє
            personal_qualities = "";//ініціалізація рядку особистих якостей
        }
        /// <summary>
        /// Деструктор
        /// </summary>
        ~CV()
        {
        }

    }
}