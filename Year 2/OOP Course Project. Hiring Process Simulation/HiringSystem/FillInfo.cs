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
    /// Вікно для введення інформації про резюме
    /// </summary>
    public partial class FillInfo : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///поточне резюме кандидата на роботу
        private CV curr_cv;
        public FillInfo(ref CV cv)
        {
            InitializeComponent();
            curr_cv = cv;//визначення поточного резюме
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступної сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            label1.Hide();//сховати надпис
            next.Hide();//сховати кнопку
            submit.Show();//показати кнопку
            label2.Show();//показати надпис
            back.Show();//показати кнопку
            CVInfoFIll.Show();//показати форму введення інформації
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до попередньої сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void back_Click(object sender, EventArgs e)
        {
            label1.Show();//показати надпис
            next.Show();//показати кнопку
            submit.Hide();//сховати кнопку
            label2.Hide();//сховати надпис
            back.Hide();//сховати кнопку
            CVInfoFIll.Hide();//сховати форму
        }
        /// <summary>
        /// Подія натиснення на кнопку для збереження введених данних
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void submit_Click(object sender, EventArgs e)
        {
            if (CVFormValidating())//якщо всі поля заповнені
            {
                curr_cv.Degree = comboBoxDegree.Text.Trim();//зберегти вчений рівень кандидата
                curr_cv.Experience = (int)numericUpDownExp.Value;//зберегти кількість років досвіду кандидата
                curr_cv.Skill_level = comboBoxSkill.Text.Trim();//обрізати пробіли з кінців рядка
                string techs = "";//ініціалізувати рядок технологій, відомих кандидатові
                for (int i = 0; i < checkedListBoxTechs.CheckedItems.Count - 1; i++)//для відмічених технологій
                {
                    techs += checkedListBoxTechs.CheckedItems[i] + ", ";//додати до рядка технологій
                }
                techs += checkedListBoxTechs.CheckedItems[checkedListBoxTechs.CheckedItems.Count - 1];//додати до рядка технологій
                curr_cv.Technologies = techs;//хюерегти технології кандидата
                string persquals = "";//ініціалізувати рядок персональних якостей кандидата
                for (int i = 0; i < checkedListBoxTechs.CheckedItems.Count - 1; i++)//для відмічених персональних якостей
                {
                    persquals += checkedListBoxTechs.CheckedItems[i] + ", ";//додати до рядка персональних якостей
                }
                persquals += checkedListBoxPersquals.CheckedItems[checkedListBoxPersquals.CheckedItems.Count - 1];//додати до рядка персональних якостей
                curr_cv.Personal_qualities = persquals;//зберегти персональні якості кандидата
                MessageBox.Show("CV was created", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);//вивести повідомлення про зберегження даних
                UserClosing = true;//встановити в режим переходу до наступного вікна
                this.Close();//закрити поточне
            }
            else
            {
                MessageBox.Show("Please input all information", "Empty data", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);//вивести повідомлення
            }
            
        }
        /// <summary>
        /// Перевірка заповненості текстових полів
        /// </summary>
        /// <returns></returns>
        private bool CVFormValidating()
        {
            if (string.IsNullOrEmpty(comboBoxDegree.Text) || string.IsNullOrEmpty(comboBoxSkill.Text) || (checkedListBoxTechs.CheckedItems.Count == 0) || (checkedListBoxPersquals.CheckedItems.Count == 0))//перевірка заповненості полів форми
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
        private void FillInfo_FormClosing(object sender, FormClosingEventArgs e)
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
