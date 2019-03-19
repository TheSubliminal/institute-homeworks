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
    /// Вікно для введення інформації про студента курсів при компанії
    /// </summary>
    public partial class CoursesTraineeInfo : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///поточний студент курсів
        private Applicant curr_ct;
        public CoursesTraineeInfo(ref CoursesTrainee ct)
        {
            InitializeComponent();
            curr_ct = ct;//визначення поточного студента курсів
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку для збереження введених данних
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void submit_Click(object sender, EventArgs e)
        {
            if (CoursesTraineeFormValidating())//якщо всі поля заповнені
            {
                curr_ct.Name = textBoxName.Text.Trim();//зберегти ім'я студента курсів
                curr_ct.Surname = textBoxSurname.Text.Trim();//зберегти прізвище студента курсів
                curr_ct.Age = (int)numericUpDownAge.Value;//зберегти вік студента курсів
                curr_ct.Email = textBoxEmail.Text.Trim();//зберегти електронну пошту студента курсів
                MessageBox.Show("Information was submitted", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);//вивести повідомлення про збереження данних
                UserClosing = true;//встановити в режим переходу до наступного вікна
                this.Close();//закрити поточне
            }
            else
            {
                MessageBox.Show("Please input all information", "Empty data", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//вивести повідомлення
            }
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступної сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            this.back.Show();//показати кнопку
            this.label1.Hide();//сховати надпис
            this.next.Hide();//сховати кнопку
            this.submit.Show();//показати кнопку
            this.label2.Show();//показати надпис
            this.CoursesTraineeInfoFill.Show();//показати форму введення інформації
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до попередньої сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void back_Click(object sender, EventArgs e)
        {
            this.back.Hide();//сховати кнопку
            this.label1.Show();//показати надпис
            this.next.Show();//показати кнопку
            this.submit.Hide();//сховати кнопку
            this.label2.Hide();//сховати надпис
            this.CoursesTraineeInfoFill.Hide();//сховати форму введення інформації
        }
        /// <summary>
        /// Перевірка заповненості текстових полів
        /// </summary>
        /// <returns></returns>
        private bool CoursesTraineeFormValidating()
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxSurname.Text) || (numericUpDownAge.Value == 0))//перевірка заповненості полів форми
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void CoursesTraineeInfo_FormClosing(object sender, FormClosingEventArgs e)
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
