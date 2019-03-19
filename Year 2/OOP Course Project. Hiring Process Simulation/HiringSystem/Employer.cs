// File:    Employer.cs
// Author:  Михайло
// Created: 30 сентября 2018 г. 18:14:31
// Purpose: Definition of Class Employer

using System;
using System.Data;
using System.Windows.Forms;
using System.IO;

namespace HiringSystem
{
    /// <summary>
    /// Клас роботодавця.
    /// </summary>
    public class Employer
    {
        ///назва компанії
        private string company_name;
        public string Company_name
        {
            get
            {
                return company_name;
            }
            set
            {
                company_name = value;
            }
        }
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
        ///HR компанії
        public HR hR;
        public HR HR
        {
            get
            {
                return hR;
            }
            set
            {
                hR = value;
            }
        }
        ///опис вакансії
        public JobDescription jobDescription;
        public JobDescription JobDescription
        {
            get
            {
                return jobDescription;
            }
            set
            {
                jobDescription = value;
            }
        }

        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public Employer()
        {
            company_name = "";//ініціалізація рядку назви компанії
            name = "";//ініціалізація рядку імені
            surname = "";//ініціалізація рядку прізвища
            hR = new HR();//ініціалізація HR
            jobDescription = new JobDescription();//ініціалізація опису вакансії
        }
        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public Employer(string cmp_nm, string nm, string surn)
        {
            company_name = cmp_nm;//ініціалізація рядку назви компанії
            name = nm;//ініціалізація рядку імені
            surname = surn;//ініціалізація рядку прізвища
            hR = new HR();//ініціалізація HR
            jobDescription = new JobDescription();//ініціалізація опису вакансії
        }
        /// <summary>
        /// Конструктор копії.
        /// </summary>
        public Employer(Employer empl)
        {
            company_name = empl.company_name;//ініціалізація рядку назви компанії
            name = empl.name;//ініціалізація рядку імені
            surname = empl.surname;//ініціалізація рядку прізвища
            hR = empl.hR;//ініціалізація HR
            jobDescription = empl.jobDescription;//ініціалізація опису вакансії
        }

        /// <summary>
        /// Конструктор перетворення.
        /// </summary>
        public Employer(string data)
        {
            company_name = data.Substring(0, 8);//ініціалізація рядку назви компанії
            name = data.Substring(8, 8);//ініціалізація рядку імені
            surname = data.Substring(16, 8);//ініціалізація рядку прізвища
            hR = new HR();//ініціалізація HR
            jobDescription = new JobDescription();//ініціалізація опису вакансії
        }
        ///деструктор
        ~Employer() {}
        /// <summary>
        /// Формування критеріїв для вакансії
        /// </summary>
        public DataTable FormJobDescription()
        {
            string myDirectory = string.Empty;//ініціалізуємо директорію
            DataTable JDtable = null;//ініціалізуємо таблицю данних
            DataSet JDs = null;//ініціалізуємо вибірку даних
            myDirectory = Directory.GetCurrentDirectory();//отримуємо значення поточної директорії
            using (StreamReader streamreader = new StreamReader(myDirectory + @"\JobDescriptionDB.xml", System.Text.Encoding.UTF8))//за допомогою інструменту читання файлу зчитауємо XML файл з базою данних
            {
                JDs = new DataSet();//створення вибірки данних
                JDs.ReadXml(streamreader, XmlReadMode.Auto);//зчитуємо у неїданні з файлу
                JDtable = JDs.Tables[0];//отриманні дані присвоюємо таблиці
            }
            return JDtable;//повертаємо таблицю данних
        }
        /// <summary>
        ///Розгляд поданих резюме
        /// </summary>
        public int[] ReviewCV(CV appl_cv)
        {
            int[] result = new int[] { 0, 0, 0, 0, 0, 0 };//масив з результатами для кожного пункту
            int cv_skill_lvl = 1;//рівень навичок зазначений в резюме кандидата
            int jd_skill_lvl = 1;//рівень навичок, необхідний для робочого місця
            switch(appl_cv.Skill_level)//встановлення цифрового рівня навичок в залежності від значення рівня навичок в резюме
            {
                case "Junior":
                    cv_skill_lvl = 1;
                    break;
                case "Middle":
                    cv_skill_lvl = 2;
                    break;
                case "Senior":
                    cv_skill_lvl = 3;
                    break;
            }
            switch (this.JobDescription.Skill_level)//встановлення цифрового рівня навичок в залежності від значення рівня навичок в описі вакансії
            {
                case "Junior":
                    jd_skill_lvl = 1;
                    break;
                case "Middle":
                    jd_skill_lvl = 2;
                    break;
                case "Senior":
                    jd_skill_lvl = 3;
                    break;
            }
            string[] separators = new string[] {", "};//роздільники рядку
            string[] main_techs = { "C++", "C#", "Python", "NodeJS", "PHP", "JavaScript", "CSS", "HTML", "Go", "React", "Angular", "Vue.js", "Ruby", "Django", "Jquery", "Java", "MongoDB" };//основні технології
            string[] cv_techs = appl_cv.Technologies.Split(separators, StringSplitOptions.RemoveEmptyEntries);//отримати масив технологій з рядка в резюме
            string[] jd_techs = this.JobDescription.Technologies.Split(separators, StringSplitOptions.RemoveEmptyEntries);//отримати масив технологій з рядка в описі вакансії
            float unlearned_techs = 0;//лічильник технологій, зазначених в описі вакансії, які не знає кандидат
            //для кожної технології з масиву технологій з опису вакансії
            foreach (string tech in jd_techs)
            {
                if (Array.IndexOf(cv_techs, tech) == -1 && Array.IndexOf(main_techs, tech) != -1)//якщо дана технологія відсутня в резюме і вона є одною з осовних технологій
                {
                    return result;//завершити перевірку резюме
                }
                else if (Array.IndexOf(cv_techs, tech) == -1)//якщо дана технологія не є основною
                {
                    result[5] -= 10 / jd_techs.Length;//відняти частину балів від кінцевого результату
                }
            }
            unlearned_techs = Math.Abs((100 / jd_techs.Length) * (result[5] / (10 / jd_techs.Length)));//визначити відсоток невідомих кандидату технологій
            //відповідно до кількості відсотків встановити оцінку пункту в масиві результатів 
            if (unlearned_techs > 75)
            {
                result[0] = 1;
            }
            else if (unlearned_techs > 25 && unlearned_techs < 50)
            {
                result[0] = 2;
            }
            else if (unlearned_techs < 25 && unlearned_techs > 0)
            {
                result[0] = 3;
            }
            else if (unlearned_techs == 0)
            {
                result[0] = 4;
                result[5] += 10;
            }
            if (cv_techs.Length > jd_techs.Length)//якщо кандидат знає більше технологій, ніж зазначено в описі вакансії
            {
                result[5] += 10;//додати балів до результату
            }
            //відповідно до рівня навичок кандидата додати або відняти бали з загального результату і дати оцінку пункту в масиві результатів
            if (jd_skill_lvl - cv_skill_lvl == 2)//якщо різниця між рівнем навичок в резюме та рівнем навичок в описі вакансії завелика
            {
                result[5] = 0;
                return result;//зупинити перевірку
            }
            else if (jd_skill_lvl == cv_skill_lvl)
            {
                result[1] = 2;
                result[5] += 10;
            }
            else if (jd_skill_lvl - cv_skill_lvl == 1)
            {
                result[1] = 1;
                result[5] -= 5;
            }
            else if (cv_skill_lvl - jd_skill_lvl == 1)
            {
                result[1] = 3;
                result[5] += 5;
            }
            else if (cv_skill_lvl - jd_skill_lvl == 2)
            {
                result[1] = 4;
                result[5] += 10;
            }
            //відповідно до кількості років досвіду кандидата додати бали до загального результату і дати оцінку пункту в масиві результатів
            if (appl_cv.Experience == this.JobDescription.Experience)
            {
                result[2] = 2;
                result[5] += 10;
            }
            else if (appl_cv.Experience > this.JobDescription.Experience)
            {
                result[2] = 4;
                result[5] += 10; 
            }
            else
            {
                result[2] = 1;
            }
            //відповідно до вченого рівня кандидата додати бали до загального результату і даємо оцінку пункту в масиві результатів
            if ((this.JobDescription.Degree == "Bachelor" && appl_cv.Degree == "Bachelor") || (this.JobDescription.Degree == "Master's" && appl_cv.Degree == "Master's"))
            {
                result[3] = 2;
                result[5] += 10;
            }
            else if (this.JobDescription.Degree == "Bachelor" && appl_cv.Degree == "Master's")
            {
                result[3] = 3;
                result[5] += 10;
            }
            else if (appl_cv.Degree == "Doctoral")
            {
                result[3] = 4;
                result[5] += 20;
            }
            else
            {
                result[3] = 1;
            }
            string[] cv_persquals = appl_cv.Personal_qualities.Split(separators, StringSplitOptions.RemoveEmptyEntries);//масив персональних якостей кандидата, зазначених в резюме
            string[] jd_persquals = this.JobDescription.Personal_qualities.Split(separators, StringSplitOptions.RemoveEmptyEntries);//масив пересональних якостей, зазначених в описі вакансії
            float unsatisfied_qualities = 0;//відсоток персональних якостей, які не має кандидат, які зазначені в описі вакансії
            int num_of_unst_qual = 0;//кількість персональних якостей, які не має кандидат, які зазначені в описі вакансії
            //для кожної персональної якості з масиву персональних якостей з опису вакансії
            foreach (string qual in jd_persquals)
            {
                if (Array.IndexOf(cv_persquals, qual) != -1)//якщо перосальна якість присутня у резюме
                {
                    result[5] += 10 / jd_persquals.Length;//додаємо частину балів від загального результату
                }
                else//якщо відсутня
                {
                    num_of_unst_qual++;//інкрементуємо лічильник відсутніх персональних якостей
                }
            }
            unsatisfied_qualities = Math.Abs((100 / jd_persquals.Length) * num_of_unst_qual);//обчислюємо відосток відсутніх персональних якостей
            //відповідно до відсотку відсутніх персональних якостей даємо оцінку пункту в масиві результатів
            if (unsatisfied_qualities > 75)
            {
                result[4] = 1;
            }
            else if (unsatisfied_qualities > 25 && unlearned_techs < 50)
            {
                result[4] = 2;
            }
            else if (unsatisfied_qualities < 25 && unsatisfied_qualities > 0)
            {
                result[4] = 3;
            }
            else if (unsatisfied_qualities == 0)
            {
                result[4] = 4;
            }
            return result;//повернути масив результатів
        }
        /// <summary>
        /// Перевірка кандидата на кримінальні записи та фінансові проблеми
        /// </summary>
        public int[] BackgroundCheck(Applicant appl)
        {
            int[] result = new int[]{0, 0, 0, 0};//масив результатів перевірки
            if (!appl.Criminal_records)//якщо у кандидата відстуні кримінальні записи
            {
                result[0]++;//збільшити оцінку поточного пунтку в масиві результатів
                result[3]++;//збільшити загальну оцінку
            }
            if (!appl.Credit_problems)//якщо у кандидата відстуні фінансові проблеми
            {
                result[1]++;//збільшити оцінку поточного пунтку в масиві результатів
                result[3]++;//збільшити загальну оцінку
            }

            if (appl.Past_employers_expression)//якщо кандидат залишив гарне враження у попередніх роботодавців
            {
                result[2]++;//збільшити оцінку поточного пунтку в масиві результатів
                result[3]++;//збільшити загальну оцінку
            }
            return result;//повернути масив результатів
        }
    }
}
