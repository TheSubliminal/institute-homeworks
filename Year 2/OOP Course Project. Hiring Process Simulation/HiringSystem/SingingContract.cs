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
    /// Вікно з додатковою інформацією
    /// </summary>
    public partial class SingingContract : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        public SingingContract()
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопки завершення програми
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void exit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);//завершити роботу програми
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
        /// Подія натискання на гіперпосилання
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            try//спробувати перейти за посиланням
            {
                VisitLink(this.linkLabel3.Text);//перейти за посиланням
            }
            catch (Exception ex)//якщо отримано помилку
            {
                MessageBox.Show("Unable to open link that was clicked.");//вивести повідомлення
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
        private void SingingContract_FormClosing(object sender, FormClosingEventArgs e)
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
