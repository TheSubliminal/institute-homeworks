namespace HiringSystem
{
    partial class CoursesTraineeInfo
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CoursesTraineeInfo));
            this.label2 = new System.Windows.Forms.Label();
            this.submit = new System.Windows.Forms.Button();
            this.next = new System.Windows.Forms.Button();
            this.CoursesTraineeInfoFill = new System.Windows.Forms.TableLayoutPanel();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxSurname = new System.Windows.Forms.TextBox();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxEmail = new System.Windows.Forms.TextBox();
            this.numericUpDownAge = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.back = new System.Windows.Forms.Button();
            this.CoursesTraineeInfoFill.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAge)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Modern No. 20", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(9, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(704, 24);
            this.label2.TabIndex = 14;
            this.label2.Text = "For further progress, please input the neccessary information about courses train" +
    "ee:";
            this.label2.Visible = false;
            // 
            // submit
            // 
            this.submit.Location = new System.Drawing.Point(745, 197);
            this.submit.Name = "submit";
            this.submit.Size = new System.Drawing.Size(75, 23);
            this.submit.TabIndex = 13;
            this.submit.Text = "Submit";
            this.submit.UseVisualStyleBackColor = true;
            this.submit.Visible = false;
            this.submit.Click += new System.EventHandler(this.submit_Click);
            // 
            // next
            // 
            this.next.Location = new System.Drawing.Point(745, 197);
            this.next.Name = "next";
            this.next.Size = new System.Drawing.Size(75, 23);
            this.next.TabIndex = 12;
            this.next.Text = "Next";
            this.next.UseVisualStyleBackColor = true;
            this.next.Click += new System.EventHandler(this.next_Click);
            // 
            // CoursesTraineeInfoFill
            // 
            this.CoursesTraineeInfoFill.BackColor = System.Drawing.SystemColors.Control;
            this.CoursesTraineeInfoFill.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Outset;
            this.CoursesTraineeInfoFill.ColumnCount = 2;
            this.CoursesTraineeInfoFill.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.CoursesTraineeInfoFill.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.CoursesTraineeInfoFill.Controls.Add(this.label5, 0, 1);
            this.CoursesTraineeInfoFill.Controls.Add(this.textBoxSurname, 1, 1);
            this.CoursesTraineeInfoFill.Controls.Add(this.textBoxName, 1, 0);
            this.CoursesTraineeInfoFill.Controls.Add(this.label3, 0, 0);
            this.CoursesTraineeInfoFill.Controls.Add(this.label4, 0, 2);
            this.CoursesTraineeInfoFill.Controls.Add(this.label6, 0, 3);
            this.CoursesTraineeInfoFill.Controls.Add(this.textBoxEmail, 1, 3);
            this.CoursesTraineeInfoFill.Controls.Add(this.numericUpDownAge, 1, 2);
            this.CoursesTraineeInfoFill.Location = new System.Drawing.Point(103, 53);
            this.CoursesTraineeInfoFill.Name = "CoursesTraineeInfoFill";
            this.CoursesTraineeInfoFill.RowCount = 4;
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.CoursesTraineeInfoFill.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.CoursesTraineeInfoFill.Size = new System.Drawing.Size(617, 137);
            this.CoursesTraineeInfoFill.TabIndex = 11;
            this.CoursesTraineeInfoFill.Visible = false;
            // 
            // label5
            // 
            this.label5.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label5.Location = new System.Drawing.Point(5, 41);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(87, 21);
            this.label5.TabIndex = 8;
            this.label5.Text = "Surname";
            // 
            // textBoxSurname
            // 
            this.textBoxSurname.Font = new System.Drawing.Font("Courier New", 12F);
            this.textBoxSurname.Location = new System.Drawing.Point(100, 39);
            this.textBoxSurname.Name = "textBoxSurname";
            this.textBoxSurname.Size = new System.Drawing.Size(325, 26);
            this.textBoxSurname.TabIndex = 6;
            // 
            // textBoxName
            // 
            this.textBoxName.Font = new System.Drawing.Font("Courier New", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxName.Location = new System.Drawing.Point(100, 5);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(325, 26);
            this.textBoxName.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Courier New", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(21, 7);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 21);
            this.label3.TabIndex = 5;
            this.label3.Text = "Name";
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label4.Location = new System.Drawing.Point(27, 75);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 21);
            this.label4.TabIndex = 7;
            this.label4.Text = "Age";
            // 
            // label6
            // 
            this.label6.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label6.Location = new System.Drawing.Point(16, 109);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(65, 21);
            this.label6.TabIndex = 10;
            this.label6.Text = "Email";
            // 
            // textBoxEmail
            // 
            this.textBoxEmail.Font = new System.Drawing.Font("Courier New", 12F);
            this.textBoxEmail.Location = new System.Drawing.Point(100, 107);
            this.textBoxEmail.Name = "textBoxEmail";
            this.textBoxEmail.Size = new System.Drawing.Size(325, 26);
            this.textBoxEmail.TabIndex = 11;
            // 
            // numericUpDownAge
            // 
            this.numericUpDownAge.Font = new System.Drawing.Font("Courier New", 12F);
            this.numericUpDownAge.Location = new System.Drawing.Point(100, 73);
            this.numericUpDownAge.Name = "numericUpDownAge";
            this.numericUpDownAge.Size = new System.Drawing.Size(70, 26);
            this.numericUpDownAge.TabIndex = 22;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(9, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(578, 168);
            this.label1.TabIndex = 10;
            this.label1.Text = "Employer needs to get some basic information about courses trainee.\r\n\r\nIt is:\r\n  " +
    " 1) Name\r\n   2) Surname\r\n   3) Age\r\n   4) Email address";
            // 
            // back
            // 
            this.back.Location = new System.Drawing.Point(13, 196);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(75, 23);
            this.back.TabIndex = 15;
            this.back.Text = "Back";
            this.back.UseVisualStyleBackColor = true;
            this.back.Visible = false;
            this.back.Click += new System.EventHandler(this.back_Click);
            // 
            // CoursesTraineeInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 227);
            this.Controls.Add(this.back);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.submit);
            this.Controls.Add(this.next);
            this.Controls.Add(this.CoursesTraineeInfoFill);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "CoursesTraineeInfo";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.CoursesTraineeInfo_FormClosing);
            this.CoursesTraineeInfoFill.ResumeLayout(false);
            this.CoursesTraineeInfoFill.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAge)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button submit;
        private System.Windows.Forms.Button next;
        private System.Windows.Forms.TableLayoutPanel CoursesTraineeInfoFill;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxSurname;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxEmail;
        private System.Windows.Forms.NumericUpDown numericUpDownAge;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button back;
    }
}