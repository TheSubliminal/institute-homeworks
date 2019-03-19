using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HiringSystem
{
    /// <summary>
    /// Вікно вибору типу процесу працевлаштування
    /// </summary>
    public partial class SelectType : Form
    {
        ///поточний тип процесу працевлаштування
        public bool curr_type;
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        public SelectType()
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натисненя на кнопку з вибором процесу працевлаштування для студента курсів
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void coursestrainee_Click(object sender, EventArgs e)
        {
            curr_type = false;//встановити поточний тип процесу як процес для студента курсів
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія натисненя на кнопку з вибором типового процесу працевлаштування
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void typical_Click(object sender, EventArgs e)
        {
            curr_type = true;//встановити поточний типовий тип процесу працевлаштування
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void SelectType_FormClosing(object sender, FormClosingEventArgs e)
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
