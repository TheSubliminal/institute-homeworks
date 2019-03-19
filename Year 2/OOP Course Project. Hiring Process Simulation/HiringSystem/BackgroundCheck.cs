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
    /// Вікно з інформацією про перевірку та результати перевірки кандидата на кримінальні записи, фінансові проблеми та враження попередніх роботодавців
    /// </summary>
    public partial class BackgroundCheck : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///номер сторінки, на якій ми знаходимось
        private int page = 0;
        ///масив результатів перевірки кандидата
        private int[] curr_results;
        public BackgroundCheck(int[] results)
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
            curr_results = results;//отримати результати перевірки
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступної сторінки з інформацією
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            if (page == 0)//якщо поточна сторінка перша
            {
                this.back.Show();//показати кнопку
                this.label1.Hide();//сховати надпис
                this.label2.Show();//показати надпис
                System.Drawing.Color label_color = System.Drawing.Color.Blue;//ініціалізація кольору надпису
                string label_text = "";//ініціалізація тексту напису
                for (int i = 0; i < 4; i++)//для кожної оцінки з масиву результатів перевірки
                {
                    SelectProperties(curr_results[i], i, ref label_color, ref label_text);//визначити властивості надпису для поточної оцінки
                    switch (i)//встановити відповідні властивості для відповідних полів
                    {
                        case 0://для поля кримінальних записів
                            this.labelCrimRec.ForeColor = label_color;
                            this.labelCrimRec.Text = label_text;
                            break;
                        case 1://для поля фінансових проблем
                            this.labelCredProbl.ForeColor = label_color;
                            this.labelCredProbl.Text = label_text;
                            break;
                        case 2://для поля враження попередніх роботодавці
                            this.labelPastEmpExp.ForeColor = label_color;
                            this.labelPastEmpExp.Text = label_text;
                            break;
                        case 3://для загальної оцінки
                            this.labelOverall.ForeColor = label_color;
                            this.labelOverall.Text = label_text;
                            break;
                    }
                }
                this.tableLayoutPanelResults.Show();//показати таблицю з оцінками
            }
            else
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
            if (page == 1)//якщо поточна сторінка друга
            {
                this.back.Hide();//сховати кнопку
                this.label1.Show();//показати надпис
                this.label2.Hide();//сховати надпис
                this.tableLayoutPanelResults.Hide();
            }
            this.page--;//зменшити номер сторінки
        }
        /// <summary>
        /// Визначення властивостей для поточного пункту відповідно до оцінок
        /// </summary>
        /// <param name="quality"></param>
        /// <param name="label_color"></param>
        /// <param name="label_text"></param>
        private void SelectProperties(int quality, int quality_id, ref System.Drawing.Color label_color, ref string label_text)
        {
            if (quality_id == 3)//якщо для загальної оцінки
            {
                switch (quality)//відповідно для поточної оцінки встановити колір та текст надпису
                {
                    case 0://для нуля червоний та "Погано"
                        label_color = System.Drawing.Color.Red;
                        label_text = "Bad";
                        break;
                    case 1://для 1 червоний та "Погано"
                        label_color = System.Drawing.Color.Red;
                        label_text = "Bad";
                        break;
                    case 2://для 2 - жовтий та "Добре"
                        label_color = System.Drawing.Color.Green;
                        label_text = "Good";
                        break;
                    case 3://для 3 - зелений та "Чудово"
                        label_color = System.Drawing.Color.Green;
                        label_text = "Brilliant";
                        break;
                }
            }
            else
            {
                switch (quality)//відповідно для поточної оцінки встановити колір та текст надпису
                {
                    case 0://для нуля червоний та "Погано"
                        label_color = System.Drawing.Color.Red;
                        label_text = "Bad";
                        break;
                    case 1://для 1 червоний та "Добре"
                        label_color = System.Drawing.Color.Green;
                        label_text = "Good";
                        break;
                }
            }
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BackgroundCheck_FormClosing(object sender, FormClosingEventArgs e)
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
