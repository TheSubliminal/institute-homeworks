namespace HiringSystem
{
    partial class SingingContract
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SingingContract));
            this.label1 = new System.Windows.Forms.Label();
            this.exit = new System.Windows.Forms.Button();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            this.linkLabel3 = new System.Windows.Forms.LinkLabel();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.author = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(803, 216);
            this.label1.TabIndex = 11;
            this.label1.Text = resources.GetString("label1.Text");
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(749, 385);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(75, 23);
            this.exit.TabIndex = 12;
            this.exit.Text = "Exit";
            this.exit.UseVisualStyleBackColor = true;
            this.exit.Click += new System.EventHandler(this.exit_Click);
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.linkLabel1.Location = new System.Drawing.Point(12, 256);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(373, 21);
            this.linkLabel1.TabIndex = 13;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "https://www.thebalancecareers.com";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.linkLabel2.Location = new System.Drawing.Point(12, 311);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(351, 21);
            this.linkLabel2.TabIndex = 14;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "https://www.smartrecruiters.com";
            this.linkLabel2.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel2_LinkClicked);
            // 
            // linkLabel3
            // 
            this.linkLabel3.AutoSize = true;
            this.linkLabel3.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.linkLabel3.Location = new System.Drawing.Point(12, 365);
            this.linkLabel3.Name = "linkLabel3";
            this.linkLabel3.Size = new System.Drawing.Size(285, 21);
            this.linkLabel3.TabIndex = 15;
            this.linkLabel3.TabStop = true;
            this.linkLabel3.Text = "https://www.testdome.com/";
            this.linkLabel3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel3_LinkClicked);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label2.Location = new System.Drawing.Point(12, 232);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(495, 24);
            this.label2.TabIndex = 16;
            this.label2.Text = "Lots of tips and information how to success in getting job:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label3.Location = new System.Drawing.Point(12, 287);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(482, 24);
            this.label3.TabIndex = 17;
            this.label3.Text = "A look on the hiring process from the point of employer:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label4.Location = new System.Drawing.Point(12, 341);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(326, 24);
            this.label4.TabIndex = 18;
            this.label4.Text = "Tests to practise before technical tests:";
            // 
            // author
            // 
            this.author.Location = new System.Drawing.Point(749, 356);
            this.author.Name = "author";
            this.author.Size = new System.Drawing.Size(75, 23);
            this.author.TabIndex = 19;
            this.author.Text = "Author info";
            this.author.UseVisualStyleBackColor = true;
            this.author.Click += new System.EventHandler(this.author_Click);
            // 
            // SingingContract
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 417);
            this.Controls.Add(this.author);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.linkLabel3);
            this.Controls.Add(this.linkLabel2);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.exit);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "SingingContract";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.SingingContract_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button exit;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.LinkLabel linkLabel2;
        private System.Windows.Forms.LinkLabel linkLabel3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button author;
    }
}