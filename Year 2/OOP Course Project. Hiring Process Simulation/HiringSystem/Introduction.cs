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
    /// Початкове вікно
    /// </summary>
    public partial class Introduction : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        public Introduction()
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Introduction_FormClosing(object sender, FormClosingEventArgs e)
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
        /// <summary>
        /// Подія натиснення на кнопку для виведення інформації про автора
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void author_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Program made by:\n\nMichael Fridrikhson\nGroup IS-72\n\nПрограма розроблена:\n\nМихайлом Фрідріхсоном\nГрупа: ІС-72\n2 курс\nНомер залікової книжки: ІС-7224");//повідомлення з інформацією про автора
        }
    }
        
}
