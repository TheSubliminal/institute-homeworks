using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HiringSystem
{
    /// <summary>
    /// Клас обробки помилок
    /// </summary>
    public class Error : Exception
    {
        ///Визначений тип помилки
        public int type;
        /// <summary>
        /// Конструктор
        /// </summary>
        public Error(int t)
        {
            type = t;
        }
        /// <summary>
        /// Деструктор
        /// </summary>
        ~Error() { }
        /// <summary>
        /// Помилка встановлення від'ємної зарплатні
        /// </summary>
        public void wage()
        {
            MessageBox.Show("Wage can't be negative.");
        }
        /// <summary>
        /// Помилка встановлення від'ємної кількості років досвіду
        /// </summary>
        public void experience()
        {
            MessageBox.Show("Years of experience can't be negative.");
        }
        /// <summary>
        /// Помилка встановлення від'ємного віку
        /// </summary>
        public void age()
        {
            MessageBox.Show("Age can't be negative.");
        }
        /// <summary>
        /// Помилка видалення з порожнього вектору - списку кандидатів на роботу.
        /// </summary>
        public void empty_list()
        {
            MessageBox.Show("List of applicants is empty. Nothing to delete.");
        }
        /// <summary>
        /// Оброблення помилок
        /// </summary>
        public void err()
        {
            switch (type)
            {
                case (1):
                    wage();
                    break;
                case (2):
                    experience();
                    break;
                case (3):
                    age();
                    break;
                case (4):
                    empty_list();
                    break;
                default:
                    break;
            }
        }

    }
}
