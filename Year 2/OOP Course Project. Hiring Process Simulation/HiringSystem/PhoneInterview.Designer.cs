namespace HiringSystem
{
    partial class PhoneInterview
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PhoneInterview));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.next = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.mailbox = new System.Windows.Forms.Button();
            this.back = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(796, 216);
            this.label1.TabIndex = 4;
            this.label1.Text = resources.GetString("label1.Text");
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label2.Location = new System.Drawing.Point(12, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(801, 456);
            this.label2.TabIndex = 5;
            this.label2.Text = resources.GetString("label2.Text");
            this.label2.Visible = false;
            // 
            // next
            // 
            this.next.Location = new System.Drawing.Point(749, 228);
            this.next.Name = "next";
            this.next.Size = new System.Drawing.Size(75, 23);
            this.next.TabIndex = 6;
            this.next.Text = "Next";
            this.next.UseVisualStyleBackColor = true;
            this.next.Click += new System.EventHandler(this.next_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label3.Location = new System.Drawing.Point(12, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(739, 48);
            this.label3.TabIndex = 8;
            this.label3.Text = "After successful phone inteview candidates are being informed by HRs of the compa" +
    "ny \r\non next steps: Face-To-Face interview and technical testing. (Press button " +
    "to continue)";
            this.label3.Visible = false;
            // 
            // mailbox
            // 
            this.mailbox.AutoSize = true;
            this.mailbox.Font = new System.Drawing.Font("Microsoft YaHei UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mailbox.Location = new System.Drawing.Point(336, 136);
            this.mailbox.Name = "mailbox";
            this.mailbox.Size = new System.Drawing.Size(171, 31);
            this.mailbox.TabIndex = 9;
            this.mailbox.Text = "Check your mailbox";
            this.mailbox.UseVisualStyleBackColor = true;
            this.mailbox.Visible = false;
            this.mailbox.Click += new System.EventHandler(this.mailbox_Click);
            // 
            // back
            // 
            this.back.Location = new System.Drawing.Point(12, 472);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(75, 23);
            this.back.TabIndex = 10;
            this.back.Text = "Back";
            this.back.UseVisualStyleBackColor = true;
            this.back.Visible = false;
            this.back.Click += new System.EventHandler(this.back_Click);
            // 
            // PhoneInterview
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 507);
            this.Controls.Add(this.back);
            this.Controls.Add(this.next);
            this.Controls.Add(this.mailbox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "PhoneInterview";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.PhoneInterview_FormClosing);
            this.Load += new System.EventHandler(this.PhoneInterview_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button next;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button mailbox;
        private System.Windows.Forms.Button back;
    }
}