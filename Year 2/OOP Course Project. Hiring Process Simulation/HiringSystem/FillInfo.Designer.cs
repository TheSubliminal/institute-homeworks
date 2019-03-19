namespace HiringSystem
{
    partial class FillInfo
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FillInfo));
            this.label1 = new System.Windows.Forms.Label();
            this.next = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.CVInfoFIll = new System.Windows.Forms.TableLayoutPanel();
            this.comboBoxSkill = new System.Windows.Forms.ComboBox();
            this.numericUpDownExp = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.comboBoxDegree = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.checkedListBoxTechs = new System.Windows.Forms.CheckedListBox();
            this.checkedListBoxPersquals = new System.Windows.Forms.CheckedListBox();
            this.submit = new System.Windows.Forms.Button();
            this.back = new System.Windows.Forms.Button();
            this.CVInfoFIll.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownExp)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label1.Location = new System.Drawing.Point(17, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(798, 360);
            this.label1.TabIndex = 1;
            this.label1.Text = resources.GetString("label1.Text");
            // 
            // next
            // 
            this.next.Location = new System.Drawing.Point(749, 366);
            this.next.Name = "next";
            this.next.Size = new System.Drawing.Size(75, 23);
            this.next.TabIndex = 2;
            this.next.Text = "Next";
            this.next.UseVisualStyleBackColor = true;
            this.next.Click += new System.EventHandler(this.next_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label2.Location = new System.Drawing.Point(17, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(415, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Fill the following information to form your CV.";
            this.label2.Visible = false;
            // 
            // CVInfoFIll
            // 
            this.CVInfoFIll.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.CVInfoFIll.BackColor = System.Drawing.SystemColors.Control;
            this.CVInfoFIll.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Outset;
            this.CVInfoFIll.ColumnCount = 2;
            this.CVInfoFIll.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.CVInfoFIll.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.CVInfoFIll.Controls.Add(this.comboBoxSkill, 1, 2);
            this.CVInfoFIll.Controls.Add(this.numericUpDownExp, 1, 1);
            this.CVInfoFIll.Controls.Add(this.label8, 0, 4);
            this.CVInfoFIll.Controls.Add(this.label5, 0, 1);
            this.CVInfoFIll.Controls.Add(this.comboBoxDegree, 1, 0);
            this.CVInfoFIll.Controls.Add(this.label3, 0, 0);
            this.CVInfoFIll.Controls.Add(this.label4, 0, 2);
            this.CVInfoFIll.Controls.Add(this.label6, 0, 3);
            this.CVInfoFIll.Controls.Add(this.checkedListBoxTechs, 1, 3);
            this.CVInfoFIll.Controls.Add(this.checkedListBoxPersquals, 1, 4);
            this.CVInfoFIll.Location = new System.Drawing.Point(12, 43);
            this.CVInfoFIll.Name = "CVInfoFIll";
            this.CVInfoFIll.RowCount = 5;
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.CVInfoFIll.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.CVInfoFIll.Size = new System.Drawing.Size(812, 317);
            this.CVInfoFIll.TabIndex = 5;
            this.CVInfoFIll.Visible = false;
            // 
            // comboBoxSkill
            // 
            this.comboBoxSkill.Font = new System.Drawing.Font("Courier New", 12F);
            this.comboBoxSkill.FormattingEnabled = true;
            this.comboBoxSkill.Items.AddRange(new object[] {
            "Junior",
            "Middle",
            "Senior"});
            this.comboBoxSkill.Location = new System.Drawing.Point(232, 73);
            this.comboBoxSkill.Name = "comboBoxSkill";
            this.comboBoxSkill.Size = new System.Drawing.Size(143, 26);
            this.comboBoxSkill.Sorted = true;
            this.comboBoxSkill.TabIndex = 8;
            // 
            // numericUpDownExp
            // 
            this.numericUpDownExp.Font = new System.Drawing.Font("Courier New", 12F);
            this.numericUpDownExp.Location = new System.Drawing.Point(232, 39);
            this.numericUpDownExp.Name = "numericUpDownExp";
            this.numericUpDownExp.Size = new System.Drawing.Size(60, 26);
            this.numericUpDownExp.TabIndex = 23;
            // 
            // label8
            // 
            this.label8.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label8.Location = new System.Drawing.Point(10, 242);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(208, 21);
            this.label8.TabIndex = 14;
            this.label8.Text = "Personal qualities";
            // 
            // label5
            // 
            this.label5.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label5.Location = new System.Drawing.Point(5, 41);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(219, 21);
            this.label5.TabIndex = 8;
            this.label5.Text = "Years of experience";
            // 
            // comboBoxDegree
            // 
            this.comboBoxDegree.Font = new System.Drawing.Font("Courier New", 12F);
            this.comboBoxDegree.FormattingEnabled = true;
            this.comboBoxDegree.Items.AddRange(new object[] {
            "Bachelor",
            "Master\'s",
            "Doctoral"});
            this.comboBoxDegree.Location = new System.Drawing.Point(232, 5);
            this.comboBoxDegree.Name = "comboBoxDegree";
            this.comboBoxDegree.Size = new System.Drawing.Size(143, 26);
            this.comboBoxDegree.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label3.Location = new System.Drawing.Point(76, 7);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(76, 21);
            this.label3.TabIndex = 5;
            this.label3.Text = "Degree";
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label4.Location = new System.Drawing.Point(49, 75);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(131, 21);
            this.label4.TabIndex = 7;
            this.label4.Text = "Skill level";
            // 
            // label6
            // 
            this.label6.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label6.Location = new System.Drawing.Point(43, 136);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(142, 21);
            this.label6.TabIndex = 10;
            this.label6.Text = "Technologies";
            // 
            // checkedListBoxTechs
            // 
            this.checkedListBoxTechs.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.checkedListBoxTechs.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkedListBoxTechs.FormattingEnabled = true;
            this.checkedListBoxTechs.Items.AddRange(new object[] {
            "Angular",
            "C#",
            "C++",
            "CSS",
            "Django",
            "Flask",
            "Git",
            "Go",
            "HTML",
            "Java",
            "JavaScript",
            "Jquery",
            "MongoDB",
            "NodeJS",
            "PHP",
            "Python",
            "React",
            "Ruby",
            "SQL",
            "Vue.js"});
            this.checkedListBoxTechs.Location = new System.Drawing.Point(274, 107);
            this.checkedListBoxTechs.MultiColumn = true;
            this.checkedListBoxTechs.Name = "checkedListBoxTechs";
            this.checkedListBoxTechs.Size = new System.Drawing.Size(490, 79);
            this.checkedListBoxTechs.Sorted = true;
            this.checkedListBoxTechs.TabIndex = 24;
            // 
            // checkedListBoxPersquals
            // 
            this.checkedListBoxPersquals.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.checkedListBoxPersquals.ColumnWidth = 250;
            this.checkedListBoxPersquals.Font = new System.Drawing.Font("Courier New", 8.25F);
            this.checkedListBoxPersquals.FormattingEnabled = true;
            this.checkedListBoxPersquals.Items.AddRange(new object[] {
            "Communicating",
            "Flexibility",
            "Good English level",
            "Leader",
            "Loyalty",
            "Motivated to grow and learn",
            "Responsibility",
            "Self-Motivated",
            "Strong work ethic",
            "Team worker"});
            this.checkedListBoxPersquals.Location = new System.Drawing.Point(265, 198);
            this.checkedListBoxPersquals.MultiColumn = true;
            this.checkedListBoxPersquals.Name = "checkedListBoxPersquals";
            this.checkedListBoxPersquals.Size = new System.Drawing.Size(508, 109);
            this.checkedListBoxPersquals.Sorted = true;
            this.checkedListBoxPersquals.TabIndex = 25;
            // 
            // submit
            // 
            this.submit.Location = new System.Drawing.Point(749, 366);
            this.submit.Name = "submit";
            this.submit.Size = new System.Drawing.Size(75, 23);
            this.submit.TabIndex = 6;
            this.submit.Text = "Submit";
            this.submit.UseVisualStyleBackColor = true;
            this.submit.Visible = false;
            this.submit.Click += new System.EventHandler(this.submit_Click);
            // 
            // back
            // 
            this.back.Location = new System.Drawing.Point(12, 365);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(75, 23);
            this.back.TabIndex = 7;
            this.back.Text = "Back";
            this.back.UseVisualStyleBackColor = true;
            this.back.Visible = false;
            this.back.Click += new System.EventHandler(this.back_Click);
            // 
            // FillInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 395);
            this.Controls.Add(this.back);
            this.Controls.Add(this.submit);
            this.Controls.Add(this.CVInfoFIll);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.next);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "FillInfo";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FillInfo_FormClosing);
            this.CVInfoFIll.ResumeLayout(false);
            this.CVInfoFIll.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownExp)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button next;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TableLayoutPanel CVInfoFIll;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button submit;
        private System.Windows.Forms.NumericUpDown numericUpDownExp;
        private System.Windows.Forms.ComboBox comboBoxSkill;
        private System.Windows.Forms.ComboBox comboBoxDegree;
        private System.Windows.Forms.CheckedListBox checkedListBoxTechs;
        private System.Windows.Forms.CheckedListBox checkedListBoxPersquals;
        private System.Windows.Forms.Button back;
    }
}