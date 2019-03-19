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
    /// Вікно для виведення інформації про результати перевірки резюме роботодавцем
    /// </summary>
    public partial class CVRevision : Form
    {
        ///індикатор переходу до наступного вікна
        private bool UserClosing;
        ///масив результатів перевірки резюме
        private int[] CVresult;
        public CVRevision(int[] CVres)
        {
            InitializeComponent();
            UserClosing = false;//встановити в режим завершення програми
            CVresult = CVres;//отримати результати перевірки резюме
        }
        /// <summary>
        /// Подія завантаження вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void CVRevision_Load(object sender, EventArgs e)
        {
            System.Drawing.Color label_color = System.Drawing.Color.Blue;//ініціалізація кольору надпису
            string label_text = "";//ініціалізація тексту напису
            for (int i = 0; i < 5; i++)//для кожної оцінки з масиву результатів перевірки
            {
                SelectProperties(CVresult[i], ref label_color, ref label_text);//визначити властивості надпису для поточної оцінки
                switch(i)//встановити відповідні властивості для відповідних полів
                {
                    case 0://для поля технологій
                        this.labelTechs.ForeColor = label_color;
                        this.labelTechs.Text = label_text;
                        break;
                    case 1://для поля навичок
                        this.labelSkill.ForeColor = label_color;
                        this.labelSkill.Text = label_text;
                        break;
                    case 2://для поля досвіду
                        this.labelExp.ForeColor = label_color;
                        this.labelExp.Text = label_text;
                        break;
                    case 3://для поля вченого ступеня
                        this.labelDegree.ForeColor = label_color;
                        this.labelDegree.Text = label_text;
                        break;
                    case 4://для поля персональних якостей
                        this.labelPersquals.ForeColor = label_color;
                        this.labelPersquals.Text = label_text;
                        break;
                }
            }
        }
        /// <summary>
        /// Подія натиснення на кнопку для переходу до наступного вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void next_Click(object sender, EventArgs e)
        {
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Визначення властивостей для поточного пункту відповідно до оцінок
        /// </summary>
        /// <param name="quality"></param>
        /// <param name="label_color"></param>
        /// <param name="label_text"></param>
        private void SelectProperties(int quality, ref System.Drawing.Color label_color, ref string label_text)
        {
            switch (quality)//відповідно для поточної оцінки встановити колір та текст надпису
            {
                case 0://для нуля червоний та "Погано"
                    label_color = System.Drawing.Color.Red;
                    label_text = "Bad";
                    break;
                case 1://для 1 - помаранчевий та "Непогано"
                    label_color = System.Drawing.Color.Orange;
                    label_text = "Not bad";
                    break;
                case 2://для 2 - жовтий та "Задовільно"
                    label_color = System.Drawing.Color.Yellow;
                    label_text = "OK";
                    break;
                case 3://для 3 - світлозелений та "Добре"
                    label_color = System.Drawing.Color.LightGreen;
                    label_text = "Good";
                    break;
                case 4://для 4 - зелений та "Чудово"
                    label_color = System.Drawing.Color.Green;
                    label_text = "Brilliant";
                    break;
            }
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void CVRevision_FormClosing(object sender, FormClosingEventArgs e)
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
