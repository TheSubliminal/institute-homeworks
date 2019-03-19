using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HiringSystem
{
    /// <summary>
    /// Людина, яка закінчила курси з певної технології при компанії.
    /// </summary>
    public class CoursesTrainee : Applicant
    {
        ///результати фінального тестування
        private int course_result;
        public int Course_result
        {
            get
            {
                return course_result;
            }
            set
            {
                course_result = value;
            }
        }

        /// <summary>
        /// Конструктор за замовчуванням.
        /// </summary>
        public CoursesTrainee()
            : base()
        {
            course_result = 0;
        }
        /// <summary>
        /// Конструктор ініціалізації.
        /// </summary>
        public CoursesTrainee(string nm, string surn, int age, string eml, bool crim_rec, bool cred_probl, bool past_empl_exp, int crs_rslt)
            : base(nm, surn, age, eml, crim_rec, cred_probl, past_empl_exp)
        {
            course_result = crs_rslt;
        }

        /// <summary>
        /// Деструктор
        /// </summary>
        ~CoursesTrainee() { }

        /// <summary>
        /// Проходження тестування в кінці курсів
        /// </summary>
        public void PassTechTest()
        {
            Random random = new Random();
            int possibility = 50;
            //визначити ймовірність отримання балу за наступними параметрами:
            if (CV.Skill_level == "Middle" || CV.Skill_level == "Senior")//рівень навичок
            {
                possibility += 20;
            }
            if (CV.Experience >= 2)//досвід
            {
                possibility += 10;
            }
            if (CV.Degree == "Master")//вчений сутпінь
            {
                possibility += 10;
            }
            int result = random.Next(0, 100 - possibility) + possibility;//розрахунок результату курсів
            if (result >= 100)
            {
                this.course_result = 100;
            }
            else
            {
                this.course_result = result;
            }

        }
    }

}
