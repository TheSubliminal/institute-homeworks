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
    /// Вікно з інформацією про інтервью та технічне тестування
    /// </summary>
    public partial class InterviewAndTest : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///номер сторінки, на якій ми знаходимось
        private int page = 0;
        public InterviewAndTest()
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
                this.label3.Show();//показати надпис
                this.label4.Show();//показати надпис
                this.linkLabel1.Show();//показати гіперпосилання
                this.linkLabel2.Show();//показати гіперпосилання
                this.linkLabel3.Show();//показати гіперпосилання
                this.linkLabel4.Show();//показати гіперпосилання
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
                this.label3.Hide();//сховати надпис
                this.label4.Hide();//сховати надпис
                this.linkLabel1.Hide();//сховати гіперпосилання
                this.linkLabel2.Hide();//сховати гіперпосилання
                this.linkLabel3.Hide();//сховати гіперпосилання
                this.linkLabel4.Hide();//сховати гіперпосилання
            }
            this.page--;//зменшити номер сторінки
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
        /// Подія натискання на гіперпосилання
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void linkLabel4_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            try//спробувати перейти за посиланням
            {
                VisitLink(this.linkLabel4.Text);//перейти за посиланням
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
        private void InterviewAndTest_FormClosing(object sender, FormClosingEventArgs e)
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
