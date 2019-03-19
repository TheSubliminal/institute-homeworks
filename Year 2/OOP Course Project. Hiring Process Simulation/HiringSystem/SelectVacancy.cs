using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.IO;

namespace HiringSystem
{
    /// <summary>
    /// Вікно для вибору вакансії, на яку відсилатиметься резюме
    /// </summary>
    public partial class SelectVacancy : Form
    {
        ///вибірка з бази данних
        private DataRow[] datarows;
        ///індикатор переходу до наступного вікна
        private bool UserClosing;
        ///максимальний індекс елементів в таблиці даних
        public int ind_max;
        ///список згенерованих роботодавців
        private List<Employer> companies = new List<Employer> { };
        ///обраний кандидатом роботодавець
        private Employer selected_company;
        ///список імен для генерації роботодавців
        private List<string> names = new List<string>{"John", "James", "Paul", "Ethan", "Felix", "George", "Max"};
        ///список прізвищ для генерації роботодавців
        private List<string> surnames = new List<string> {"Miller", "Roberts", "Silvers", "Martins", "Lee", "Torvalds"};
        ///список назв компаній для генерації роботодавців
        private List<string> company_names = new List<string> {"Aperture", "Brainstorm", "Apash", "TechWorld", "PowerCode", "DataTrans", "GameStar", "GOG", "TechReflex", "TechnoSight", "CodeStart", "ARK", "Nerd", "ArchTech", "LinusTronics"};
        ///список адрес електронних пошт для генерації HR роботодавців
        private List<string> hr_emails = new List<string> {"company.hr@gmail.com", "inform@contact.us", "reply@yahoo.com", "deliver@contact.me", "company_HR@gmail.com", "job_inform@gmail.com", "infrormation@contact.us"};
        public SelectVacancy(ref Employer empl, DataTable JDtbl)
        {
            InitializeComponent();
            selected_company = empl;//отримати об'єкт ораного роботодавця
            UserClosing = false;//встановити в режим завершення програми
            this.datarows = JDtbl.Select();//ініціалізувати вибірку всіх данних з бази данних 
            ind_max = datarows.Length;//визначити максимальний індекс елементів
            Random random = new Random();//інііалізувати генератор випадкових чисел
            for (int i = 0; i <= ind_max; i++)//для всіх елементів бази данних
            {
                int cmp_name_ind = random.Next(0, company_names.Count);//випадковим чином вибрати індекс зі списку назв компаній 
                Employer employer = new Employer(company_names[cmp_name_ind], names[random.Next(0, names.Count)], surnames[random.Next(0, surnames.Count)]);//випадковим чином згенерувати ім'я та прізвище роботодавця, створити новий об'єкт роботдавця
                company_names.RemoveAt(cmp_name_ind);//видалити назву використаної компанії зі списку компаній
                employer.HR.Email = hr_emails[random.Next(0, hr_emails.Count)];//випадковим чином обрати адресу електронної пошти для HR роботодавця
                companies.Add(employer);//додати створеного роботодвця до списку компаній
            }
        }
        /// <summary>
        /// Подія завантаження вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SelectVacancy_Load(object sender, EventArgs e)
        {
            string position = string.Empty;//ініціалізувати рядок назви позиції
            string degree = string.Empty;//ініціалізувати рядок вченого рівня
            string experience = string.Empty;//ініціалізувати рядок кількості років досвіду
            string skill_lvl = string.Empty;//ініціалізувати рядок рівня навичок
            string techs = string.Empty;//ініціалізувати рядок технологій
            string pers_qual = string.Empty;//ініціалізувати рядок персональних якостей
            string wage = string.Empty;//ініціалізувати рядок зарплатні
            int column = 0;//стовпець таблиці вакансій
            int row = 1;//рядок таблиці вакансій
            string label_text;//рядок тексту надпису
            for (int i = 0; i < ind_max; i++)//для всіх елементів вибірки з таблиці даних
            {
                position = datarows[i]["position"].ToString();//отримання назви позиції поточної вакансії з вибірки данних
                companies[i].JobDescription.Position = position;//встановлення назви позиції поточної вакансії для опису вакансії компанії зі списку компаній
                degree = datarows[i]["degree"].ToString();//отримання вченого рівня поточної вакансії з вибірки данних
                companies[i].JobDescription.Degree = degree;//встановлення вченого рівня поточної вакансії для опису вакансії компанії зі списку компаній
                experience = datarows[i]["experience"].ToString();//отримання кількості років досвіду поточної вакансії з вибірки данних
                companies[i].JobDescription.Experience = Int32.Parse(experience);//встановлення кількості років досвіду поточної вакансії для опису вакансії компанії зі списку компаній
                skill_lvl = datarows[i]["skilllevel"].ToString();//отримання рівня навичок поточної вакансії з вибірки данних
                companies[i].JobDescription.Skill_level = skill_lvl;//встановлення рівня навичок поточної вакансії для опису вакансії компанії зі списку компаній
                techs = datarows[i]["technologies"].ToString();//отримання технологій поточної вакансії з вибірки данних
                companies[i].JobDescription.Technologies = techs;//встановлення технологій поточної вакансії для опису вакансії компанії зі списку компаній
                pers_qual = datarows[i]["personalqualities"].ToString();//отримання персональних якостей поточної вакансії з вибірки данних
                companies[i].JobDescription.Personal_qualities = pers_qual;//встановлення персональних якостей поточної вакансії для опису вакансії компанії зі списку компаній
                wage = datarows[i]["wage"].ToString();//отримання зврплатні поточної вакансії з вибірки данних
                companies[i].JobDescription.Wage = Int32.Parse(wage);//встановлення зврплатні поточної вакансії для опису вакансії компанії зі списку компаній
                label_text = "Company: " + companies[i].Company_name + "\nPosition: " + position + "\nDegree: " + degree + "\nYears of experience: " + experience + "\nSkill level: " + skill_lvl + "\nTechnologies: " + techs;//створення тексту надпису для поточної компанії
                if (!string.IsNullOrEmpty(pers_qual))//якщо в описі вакансії присутні бажані персональні якості кандидата
                {
                    label_text += "\nPersonal Qualities: " + pers_qual;//додати їх до тексту надпису
                }
                label_text += "\nWage: " + wage + "$";//додати зарплатню до тексту надпису
                Label jdlabel = new Label{BackColor = Color.OldLace, Cursor = Cursors.Hand, Dock = DockStyle.Fill, UseMnemonic = false, Text = label_text};//створити об'єкт надпису
                jdlabel.Click += (obj, eArgs) =>//додати обробник події натиснення на надпис
                {
                    jdlabel.BorderStyle = BorderStyle.Fixed3D;//змінення вигляду надпису
                    Employer found_company = FindCompany(jdlabel.Text.Substring(jdlabel.Text.IndexOf(':') + 2, (jdlabel.Text.IndexOf('\n') - jdlabel.Text.IndexOf(':')) - 2));//визначити роботодавця, інформаця про вакансію якого виведене на надписі
                    DialogResult dialogResult = MessageBox.Show("Do you whant to submit yout CV to the " + found_company.Company_name + "?", "Submit CV?", MessageBoxButtons.YesNo);//спитати підтвердження користувача про відслання резюме до обраного роботодавця
                    if (dialogResult == DialogResult.Yes)//якщо користувач підтверджує
                    {
                        selected_company.Company_name = found_company.Company_name;//встановити назву обраної компанії
                        selected_company.Name = found_company.Name;//встановити ім'я роботодавця обраної компанії
                        selected_company.Surname = found_company.Surname;//встановити прізвище роботодавця обраної компанії
                        selected_company.HR.Company_name = found_company.Company_name;//встановити назву компанії HR обраного роботодавця
                        selected_company.HR.Email = found_company.HR.Email;//встановити адресу електронної пошти HR обраного роботодавця
                        selected_company.JobDescription.Degree = found_company.JobDescription.Degree;//встановити вчений рівень опису вакансії обраного роботодавця
                        selected_company.JobDescription.Experience = found_company.JobDescription.Experience;//встановити кільксіть років досвіду опису вакансії обраного роботодавця
                        selected_company.JobDescription.Position = found_company.JobDescription.Position;//встановитиназву вакансії обраного роботодавця
                        selected_company.JobDescription.Skill_level = found_company.JobDescription.Skill_level;//встановити рівень навичок опису вакансії обраного роботодавця
                        selected_company.JobDescription.Personal_qualities = found_company.JobDescription.Personal_qualities;//встановити персональні якості опису вакансії обраного роботодавця
                        selected_company.JobDescription.Technologies = found_company.JobDescription.Technologies;//встановити технології опису вакансії обраного роботодавця
                        selected_company.JobDescription.Wage = found_company.JobDescription.Wage;//встановити зарплатню в описі вакансії обраного роботодавця
                        UserClosing = true;//встановити в режим переходу до наступного вікна
                        this.Close();//закрити поточне
                    }
                    else
                    {
                        jdlabel.BorderStyle = BorderStyle.None;//повернути вигляд надпису до звичайного
                    }
                };
                tableLayoutPanel1.Controls.Add(jdlabel, column, row);//додати надпис у визначену позицію таблиці 
                column++;//інкрементувати номер стовпця таблиці
                if (column > 2)//якщо більше за 2
                {
                    column = 0;//обнулити
                    row++;//перейти на наступний рядок
                }
            }
        }
        /// <summary>
        /// Пошук компанії зі списку компаній за назвою компанії
        /// </summary>
        /// <param name="company_name"></param>
        /// <returns></returns>
        private Employer FindCompany(string company_name)
        {
            for (int i = 0 ; i <= ind_max; i++)//по всім елементам зі списку
            {
                if (companies[i].Company_name == company_name)//якщо назви компаній співпадають
                {
                    return companies[i];//повернути знайдену компанію
                }
            }
            return null;
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SelectVacancy_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (UserClosing)//якщо визначено перехід до наступного вікна
            {
                return;//закрити поточне
            }
            else//в іншому випадку
            {
                Environment.Exit(0);//завершити роботу програми
            }
        }
    }
}
