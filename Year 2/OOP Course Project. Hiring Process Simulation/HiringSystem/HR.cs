// File:    HR.cs
// Author:  Михайло
// Created: 30 сентября 2018 г. 18:14:32
// Purpose: Definition of Class HR

using System;
using System.Windows.Forms;

namespace HiringSystem
{
    /// <summary>
    /// Клас HR компанії.
    /// </summary>
    public class HR
    {
        ///назва компанії, від якої звертається
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

        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public HR()
        {
            company_name = "";//ініціалізація рядку назви компанії
            email = "";//ініціалізація рядку електронної пошти
        }
        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public HR(string cmp_nm, string eml)
        {
            company_name = cmp_nm;//ініціалізація рядку назви компанії
            email = eml;//ініціалізація рядку електронної пошти
        }
        /// <summary>
        /// Конструктор копії.
        /// </summary>
        public HR(HR hr)
        {
            company_name = hr.company_name;//ініціалізація рядку назви компанії
            email = hr.email;//ініціалізація рядку електронної пошти
        }

        /// <summary>
        /// Конструктор перетворення.
        /// </summary>
        public HR(string data)
        {
            company_name = data.Substring(0, 8);//ініціалізація рядку назви компанії
            email = data.Substring(8, 8);//ініціалізація рядку електронної пошти
        }
        ///деструктор
        ~HR()
        {}

        /// <summary>
        /// Відсилання листів, щодо затвердження на вакансію
        /// </summary>
        public void SendAcceptionLetter(Applicant appl)
        {
            MessageBox.Show("1 new message recieved!");//вивести повідомлення з інформацією
            MessageBox.Show(String.Format("From: {0}\nTo: {1}\n\nDear {2} {3}, we are informing you that your \napplication was accepted and we\nare inviting you to sign contract on MM.DD.YYYY at HH.MM.\n\n{4} CEO", this.Email, appl.Email, appl.Name, appl.Surname, this.Company_name));//вивести повідомлення з інформацією про запрошення на роботу
        }
        /// <summary>
        /// Відсилання листів, щодо відмови на вакансію
        /// </summary>
        public void SendDenialLetter(Applicant appl)
        {
            MessageBox.Show("1 new message recieved!");//вивести повідомлення з інформацією
            MessageBox.Show(String.Format("From: {0}\nTo: {1}\n\nDear {2} {3}, we are sorry, but your application \nunfortunately was denied.\n\nBest wishes,\n\n{4} CEO", this.Email, appl.Email, appl.Name, appl.Surname, this.Company_name));//вивести повідомлення з інформацією про заперечення кандидатура на вакансію
        }
        /// <summary>
        /// Відсилання інформаційних листів, про майбутні події
        /// </summary>
        public void SendEventInfoLetter(Applicant appl)
        {
            MessageBox.Show("1 new message recieved!");//вивести повідомлення з інформацією
            MessageBox.Show(String.Format("From: {0}\nTo: {1}\n\nDear {2} {3}, we are inviting you to pass an interview and \na technical test at our office on MM.DD.YYYY at HH.MM.\n\n{4} CEO", this.Email, appl.Email, appl.Name, appl.Surname, this.Company_name));//вивести повідомлення з інформацією про майбутні події
        }

        ///список кандидатів на роботу
        public System.Collections.ArrayList applicant;

        /// <summary>
        /// Аксесори для списку кандидатів
        /// </summary>
        public System.Collections.ArrayList Applicant
        {
            get
            {
                if (applicant == null)//якщо список пустий
                    applicant = new System.Collections.ArrayList();//створити новий об'єкт списку
                return applicant;
            }
            set
            {
                RemoveAllApplicant();//видалити  всіх кандидатів зі списку
                if (value != null)//якщо список пустий
                {
                    foreach (Applicant oApplicant in value)//для кожного кандидату
                        AddApplicant(oApplicant);//додати до списку
                }
            }
        }

        /// <summary>
        /// Додати кандидата до списку
        /// </summary>
        public void AddApplicant(Applicant newApplicant)
        {
            if (newApplicant == null)//якщо об'єкт пустий
                return;//завершити роботи
            if (this.applicant == null)//якщо поточний список пустий
                this.applicant = new System.Collections.ArrayList();//створити новий
            if (!this.applicant.Contains(newApplicant))//якщо список не містить поточного кандидата
                this.applicant.Add(newApplicant);//додати його до списку
        }

        /// <summary>
        /// Видалити кандидата зі списку
        /// </summary>
        public void DeleteApplicants(Applicant oldApplicant)
        {
            try
            {
                if (this.applicant == null)//якщо вектор пустий
                {
                    throw new Error(4);//викликати обробник помилок
                }
                if (oldApplicant == null)//якщо об'єкт пустий
                    return;//вийти з фукнції
                if (this.applicant != null)//якщо список не пустий
                    if (this.applicant.Contains(oldApplicant))//якщо він містить кандидата
                        this.applicant.Remove(oldApplicant);//видалити його зі списку
            }
            catch (Error e)
            {
                e.err();//обробити помилку
            }
        }

        /// <summary>
        /// Видалити всіх кандидатів на роботу зі списку
        /// </summary>
        public void RemoveAllApplicant()
        {
            if (applicant != null)//якщо список не пустий
                applicant.Clear();//очистити його
        }
    }
}
