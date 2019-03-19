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
    /// Вікно з інформацією про стажування
    /// </summary>
    public partial class Internship : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///номер сторінки, на якій ми знаходимось
        private int page = 0;
        public Internship()
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступної сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            if (this.page == 0)//якщо поточна сторінка перша
            {
                this.back.Show();//показати кнопку
                this.label1.Hide();//сховати надпис
                this.label2.Show();//показати надпис
            }
            else if (this.page == 1)//якщо поточна сторінка друга
            {
                UserClosing = true;//встановити в режим переходу до наступного вікна
                this.Close();//закрити поточне
            }
            this.page++;//збільшити номер сторінки
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до попередньої сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void back_Click(object sender, EventArgs e)
        {
            if (this.page == 1)//якщо поточна сторінка друга
            {
                this.back.Hide();//сховати кнопку
                this.label1.Show();//показати надпис
                this.label2.Hide();//сховати надпис
            }
            this.page--;//зменшити номер сторінки
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Internship_FormClosing(object sender, FormClosingEventArgs e)
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
