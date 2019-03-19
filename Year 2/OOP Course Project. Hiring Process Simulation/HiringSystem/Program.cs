using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data;

namespace HiringSystem
{
    /// <summary>
    /// Головний виконуючий клас програми
    /// </summary>
    static class Program
    {
        /// <summary>
        /// Головна точка входу у програму
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Start://маркер початкової форми
            Application.Run(new Introduction());//виклик початкового вікна
            Employer employer = new Employer();//створення об'єкту роботодавця
            SelectType selection = new SelectType();//створення об'єкту вікна вибору типу процесу працевлаштування
            Application.Run(selection);//виклик вікна вибору типу процесу працевлаштування
            if (selection.curr_type)//якщо вибрано типовий процес працевлаштування
            {
                Applicant applicant = new Applicant();//стоврення об'єкту кандидата на роботу
                Application.Run(new ApplicantInfo(ref applicant));//виклик вікна для введення інформації про кандидата на роботу
                applicant.CreateCV();//заповнення резюме кандидата на роботу
                applicant.FindOpening();//виклик вікна для вибору вакансії, на яку буде відсилатися заявка кандидата на роботу 
                applicant.SendCV(ref employer, employer.FormJobDescription());//відіслати резюме на розгляд роботодавцю
                int[] CVresult = employer.ReviewCV(applicant.CV);//розляд резюме роботодавцем
                Application.Run(new CVRevision(CVresult));//виклик вікна для зображення результатів перегляду резюме
                if (CVresult[5] < 10)//якщо результати занадто низькі
                {
                    Application.Run(new FailedInfo("Your CV doesn't correspond the vacancy's requirements"));//виклик вікна з повідомленням про невдачу
                    goto Start;//якщо користувач бажає спробувати ще раз - перевести його до початку процесу
                }
                else//в іншому випадку
                {
                    Application.Run(new PhoneInterview(applicant, employer));//викликати вікно з інформацією про телефонне інтервью
                    employer.HR.AddApplicant(applicant);//додати кандидата до списків HR
                    Application.Run(new InterviewAndTest());//викликати вікно з інформацією про інтервью татестування
                    int[] backcheck_results = employer.BackgroundCheck(applicant);//отримати результати перевірки кандидата на фінансові проблеми та кримінальні записи, враження попередніх роботодавців
                    Application.Run(new BackgroundCheck(backcheck_results));//викликати вікно з результатами перевірки кандидата на фінансові проблеми та кримінальні записи, враження попередніх роботодавців
                    if (backcheck_results[3] < 2)//якщо результати незадовільні
                    {
                        employer.HR.SendDenialLetter(applicant);//надіслати лист з відмовою
                        employer.HR.DeleteApplicants(applicant);//видалити зі списків HR
                        Application.Run(new FailedInfo("Your background data isn't good enough for this job."));//виклик вікна з повідомленням про невдачу
                        goto Start;//якщо користувач бажає спробувати ще раз - перевести його до початку процесу
                    }
                    else//в іншому випадку
                    {
                        Application.Run(new Internship());//викликати вікно з інформацією про стажування
                        employer.HR.SendAcceptionLetter(applicant);//надіслати кандидату листа з запрошенням на роботу
                        Application.Run(new SingingContract());//викликати вікно з додатковою інформацією 
                    }
                }
            }
            else//в іншому випадку
            {
                CoursesTrainee courses_trainee = new CoursesTrainee();//створити об'єкт класу "Студент курсів"
                Application.Run(new CoursesTraineeInfo(ref courses_trainee));//виклик вікна для отримання інформації про студента курсів
                Application.Run(new CoursesInfo());//виклик вікна з інформацією про курси в IT компаніях
                employer.HR.AddApplicant(courses_trainee);//додати студента до списків HR
                Application.Run(new Internship());//викликати вікно з інформацією про стажування
                Application.Run(new SingingContract());//викликати вікно з додатковою інформацією 
            }
        }
    }
}
