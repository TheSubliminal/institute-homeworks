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
    /// Вікно з інформацією про  пошук вакансії
    /// </summary>
    public partial class FindVacancy : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        public FindVacancy()
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія настикання кнопки переходу до наступного вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія натискання на гіперпосилання
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            try//спробувати перейти за посиланням
            {
                VisitLink(this.linkLabel1.Text);//перейти за посиланням
            }
            catch (Exception ex)//якщо отримано помилку
            {
                MessageBox.Show("Unable to open link that was clicked.");//вивести повідомлення
            }  
        }
        /// <summary>
        /// Подія натискання на гіперпосилання
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            try//спробувати перейти за посиланням
            {
                VisitLink(this.linkLabel2.Text);//перейти за посиланням
            }
            catch (Exception ex)//якщо отримано помилку
            {
                MessageBox.Show("Unable to open link that was clicked.");//вивести повідомлення
            }  
        }  
        /// <summary>
        /// Виклик браузера для переходу за посиланням
        /// </summary>
        /// <param name="link"></param>
        private void VisitLink(string link)
        {
            System.Diagnostics.Process.Start(link);//Виклик браузера для переходу за посиланням
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void FindVacancy_FormClosing(object sender, FormClosingEventArgs e)
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
