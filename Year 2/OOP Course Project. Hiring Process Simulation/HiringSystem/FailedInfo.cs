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
    /// Вікно з повідомленням про невдачу
    /// </summary>
    public partial class FailedInfo : Form
    {
        ///індикатор переходу до наступного вікна
        public bool UserClosing;
        ///рядок з причиною невдачі
        private string reason;
        public FailedInfo(string rsn)
        {
            InitializeComponent();
            reason = rsn;//отримання рядка з причиною невдачі
            UserClosing = false;//встановити в режим завершення програми
        }
        /// <summary>
        /// Подія натиснення на кнопку для повторення спроби
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            UserClosing = true;//встановити в режим переходу до наступного вікна
            this.Close();//закрити поточне
        }
        /// <summary>
        /// Подія натиснення на кнопку для завершеня роботи програми
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);//завершити роботу програми
        }
        /// <summary>
        /// Подія завантаження вінка
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void FailedInfo_Load(object sender, EventArgs e)
        {
            string label_text ="Unfortunately, you failed to get the job for the reason:\n" + reason + "\n\nDo you want to try again?";//формування рядку з причиною невдачі
            Label label = new Label { Location = new Point(13, 13), UseMnemonic = false, Text = label_text, Font = new Font("Modern No. 20", 16), Size = new Size(800, 300) };//стоврення надпису з причиною невдачі
            this.Controls.Add(label);//додавання надпису у вікно
        }
        /// <summary>
        /// Подія закриття вікна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void FailedInfo_FormClosing(object sender, FormClosingEventArgs e)
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
        /// <summary>
        /// Подія натиснення на кнопку для виведення інформації про автора
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void author_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Program made by:\n\nMichael Fridrikhson\nGroup IS-72\n\nПрограма розроблена:\n\nМихайлом Фрідріхсоном\nГрупа: ІС-72\n2 курс\nНомер залікової книжки: ІС-7224");//повідомлення з інформацією про автора
        }
    }
}
