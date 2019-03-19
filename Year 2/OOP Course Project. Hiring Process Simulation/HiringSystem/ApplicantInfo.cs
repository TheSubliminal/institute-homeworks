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
    /// Вікно для введення інформації про кандидата на роботу
    /// </summary>
    public partial class ApplicantInfo : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///поточний кандидат на роботу
        private Applicant curr_appl;
        public ApplicantInfo(ref Applicant appl)
        {
            InitializeComponent();
            curr_appl = appl;//визначення поточного кандидата
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку для збереження введених данних
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void submit_Click(object sender, EventArgs e)
        {
            if (ApplicantFormValidating())//якщо всі поля заповнені
            {
                curr_appl.Name = textBoxName.Text.Trim();//зберегти ім'я кандидата на роботу
                curr_appl.Surname = textBoxSurname.Text.Trim();//зберегти прізвище кандидата на роботу
                curr_appl.Age = (int)numericUpDownAge.Value;//зберегти вік кандидата на роботу
                curr_appl.Email = textBoxEmail.Text.Trim();//зберегти електронну пошту кандидата на роботу
                curr_appl.Criminal_records = radioButtonCrimRec1.Checked ? true : false;//зберегти інформацію про кримінальні записи кандидата на роботу
                curr_appl.Credit_problems = radioButtonCredProbl1.Checked ? true : false;//зберегти інформацію про фінансові проблеми кандидата на роботу
                curr_appl.Past_employers_expression = radioButtonPastEmplExp1.Checked ? true : false;//зберегти інформацію про враження попередніх роботодавців кандидата на роботу
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
            this.label1.Hide();//сховати надпис
            this.next.Hide();//сховати кнопку
            this.submit.Show();//показати кнопку підтвердження
            this.label7.Show();//показати надпис
            this.back.Show();//показати кнопку
            this.ApplicantInfoFill.Show();//показати форму введення інформації
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до попередньої сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void back_Click(object sender, EventArgs e)
        {
            this.label1.Show();//показати надпис
            this.next.Show();//показати кнопку
            this.submit.Hide();//сховати кнопку
            this.label7.Hide();//сховати надпис
            this.back.Hide();//сховати кнопку
            this.ApplicantInfoFill.Hide();//сховати форму
        }
        /// <summary>
        /// Перевірка заповненості текстових полів
        /// </summary>
        /// <returns></returns>
        private bool ApplicantFormValidating()
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxSurname.Text) || (numericUpDownAge.Value == 0) || (!radioButtonCredProbl1.Checked && !radioButtonCredProbl2.Checked) || (!radioButtonCrimRec1.Checked && !radioButtonCrimRec2.Checked) || (!radioButtonPastEmplExp1.Checked && !radioButton5.Checked))//перевірка заповненості полів форми
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
        private void ApplicantInfo_FormClosing(object sender, FormClosingEventArgs e)
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
