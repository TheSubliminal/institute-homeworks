// File:    Applicant.cs
// Author:  Михайло
// Created: 30 сентября 2018 г. 18:14:29
// Purpose: Definition of Class Applicant

using System;
using System.Windows.Forms;
using System.Data;

namespace HiringSystem
{
    /// <summary>
    /// Клас подавача заявки на роботу.
    /// </summary>
    public class Applicant
    {
        ///ім'я
        private string name;
        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        ///прізвище
        private string surname;
        public string Surname
        {
            get
            {
                return surname;
            }
            set
            {
                surname = value;
            }
        }
        ///вік
        private int age;
        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                try
                {
                    if (value < 0)//при встановлення від'ємного значення необхідної кількості років досвіду
                    {
                        throw new Error(3);//викликати обробник помилок
                    }
                    age = value;
                }
                catch (Error e)
                {
                    e.err();//обробити помилку
                }
            }
        }
        ///електронна пошта
        private string email;
        public string Email
        {
            get
            {
                return email;
            }
            set
            {
                email = value;
            }
        }
        ///кримінальні записи
        private bool criminal_records;
        public bool Criminal_records
        {
            get
            {
                return criminal_records;
            }
            set
            {
                criminal_records = value;
            }
        }
        ///фінансові проблеми
        private bool credit_problems;
        public bool Credit_problems
        {
            get
            {
                return credit_problems;
            }
            set
            {
                credit_problems = value;
            }
        }
        ///враження попередніх роботодавців
        private bool past_employers_expression;
        public bool Past_employers_expression
        {
            get
            {
                return past_employers_expression;
            }
            set
            {
                past_employers_expression = value;
            }
        }
        ///резюме
        private CV cV { get; set; }
        public CV CV
        {
            get
            {
                return cV;
            }
            set
            {
                cV = value;
            }
        }
        /// <summary>
        /// Перевантаження методу порівняння: порівняння на ідентичність двох персон канддатів на роботу
        /// </summary>
        /// <param name="o"></param>
        /// <returns></returns>
        public override bool Equals(object o)
        {
            var appl = o as Applicant;
            if (appl.name == this.name && appl.surname == this.surname)
                return true;
            else
                return false;
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public Applicant()
        {
            name = "";//ініціалізація рядку імені
            surname = "";//ініціалізація рядку прізвища
            age = 0;//ініціалізація віку
            email = "";//ініціалізація рядку електронної пошти
            criminal_records = false;//ініціалізація наявності кримінальних записів
            credit_problems = false;//ініціалізація наявності фінансових проблем
            past_employers_expression = false;//ініціалізація загального враження попередніх роботодавців
            cV = new CV();//ініціалізація резюме
        }

        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public Applicant(string nm, string surn, int ag, string eml, bool crim_rec, bool cred_probl, bool past_empl_exp)
        {
            name = nm;//ініціалізація рядку імені
            surname = surn;//ініціалізація рядку прізвища
            age = ag;//ініціалізація віку
            email = eml;//ініціалізація рядку електронної пошти
            criminal_records = crim_rec;//ініціалізація наявності кримінальних записів
            credit_problems = cred_probl;//ініціалізація наявності фінансових проблем
            past_employers_expression = past_empl_exp;//ініціалізація загального враження попередніх роботодавців
            cV = new CV();//ініціалізація резюме
        }

        /// <summary>
        /// Конструктор копії.
        /// </summary>
        public Applicant(Applicant appl)
        {
            name = appl.name;//ініціалізація рядку імені
            surname = appl.surname;//ініціалізація рядку прізвища
            age = appl.age;//ініціалізація віку
            email = appl.email;//ініціалізація рядку електронної пошти
            criminal_records = appl.criminal_records;//ініціалізація наявності кримінальних записів
            credit_problems = appl.credit_problems;//ініціалізація наявності фінансових проблем
            past_employers_expression = appl.past_employers_expression;//ініціалізація загального враження попередніх роботодавців
            cV = appl.cV;//ініціалізація резюме
        }

        /// <summary>
        /// Конструктор перетворення.
        /// </summary>
        public Applicant(double ag)
        {
            name = "";//ініціалізація рядку імені
            surname = "";//ініціалізація рядку прізвища
            age = (int)ag;//ініціалізація віку
            email = "";//ініціалізація рядку електронної пошти
            criminal_records = false;//ініціалізація наявності кримінальних записів
            credit_problems = false;//ініціалізація наявності фінансових проблем
            past_employers_expression = false;//ініціалізація загального враження попередніх роботодавців
            cV = new CV();//ініціалізація резюме
        }
        /// <summary>
        /// Деструктор
        /// </summary>
        ~Applicant() {}
        /// <summary>
        /// Створення резюме
        /// </summary>
        public void CreateCV()
        {
            CV curr_cv = this.CV;//отримання об'єкту резюме кандидата
            Application.Run(new FillInfo(ref curr_cv));//виклик вікна з формою для заповнення резюме кандидата
            this.CV = curr_cv;//прсвоєння створеного резюме кандидатові
        }
        /// <summary>
        /// Пошук вакасії
        /// </summary>
        public void FindOpening()
        {
            Application.Run(new FindVacancy());//виклик вікна з інформацією про пошук вакансії
        }
        /// <summary>
        /// Надсилання резюме
        /// </summary>
        public void SendCV(ref Employer empl, DataTable JDtbl)
        {
            Application.Run(new SelectVacancy(ref empl, JDtbl));//виклик вікна для вибору компанії, в яку кандидат надсилатиме своє резюме
        }
    }
}
