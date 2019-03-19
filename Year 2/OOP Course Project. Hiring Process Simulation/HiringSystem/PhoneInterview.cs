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
    /// Вікно з інформацією про телефонне інтервью
    /// </summary>
    public partial class PhoneInterview : Form
    {
        ///поточний кандидат на роботу
        private Applicant curr_appl;
        ///поточний роботодавець
        private Employer curr_empl;
        ///індикатор переходу до наступного вікна
        private bool UserClosing;
        ///номер сторінки, на якій ми знаходимось
        private int page = 0;
        public PhoneInterview(Applicant appl, Employer empl)
        {
            InitializeComponent();
            curr_appl = appl;//присвоєння поточного кандидата на роботу
            curr_empl = empl;//присвоєння поточного роботодавця
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступної сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            if (this.page == 0)//якщо ми знаходимось на першій сторінці з інформацією
            {
                this.label1.Hide();//сховати надпис
                this.label2.Show();//показати надпис
                this.back.Show();//показати кнопку
                this.next.Location = new Point(749, 472);//перемістити кнопку
                this.Size = new Size(852, 545);//змінити розмыр вікна
            }
            else if (this.page == 1)//якщо ми знаходимось на другій сторінці з інформацією
            {
                this.label2.Hide();//сховати надпис
                this.label3.Show();//показати надпис
                this.mailbox.Show();//показати кнопку
                this.back.Location = new Point(12, 225);//змінити положення кнопки
                this.Size = new Size(852, 300);//змінити розмір вікна
            }
            this.page++;//інкрементувати номер сторінки
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до попередньої сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void back_Click(object sender, EventArgs e)
        {
            if (this.page == 1)//якщо ми знаходимось на другій сторінці з інформацією
            {
                this.label1.Show();//показати надпис
                this.label2.Hide();//сховати надпис
                this.back.Hide();//сховати кнопку
                this.Size = new Size(852, 300);//змінити розмір вікна
                this.next.Location = new Point(749, 228);//змінити положення кнопки
            }
            else if (this.page == 2)//якщо ми знаходимось на третій сторінці з інформацією
            {
                this.label2.Show();//показати надпис
                this.label3.Hide();//сховати надпис
                this.mailbox.Hide();//сховати кнопку
                this.next.Location = new Point(749, 472);//змінити положення кнопки
                this.Size = new Size(852, 545);//змінити розмір вікна
                this.back.Location = new Point(12, 472);//змінити положення кнопки
            }
            this.page--;//декрементувати номер сторінки
        }
        /// <summary>
        /// Подія натиснення на кнопку для виведення листа від компанії
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void mailbox_Click(object sender, EventArgs e)
        {
            curr_empl.HR.SendEventInfoLetter(curr_appl);//надіслати запрошення на інтервью та тестування кандидату 
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія завантаження вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void PhoneInterview_Load(object sender, EventArgs e)
        {
            this.Size = new Size(852, 300); //встановити розмір вікна
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void PhoneInterview_FormClosing(object sender, FormClosingEventArgs e)
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
