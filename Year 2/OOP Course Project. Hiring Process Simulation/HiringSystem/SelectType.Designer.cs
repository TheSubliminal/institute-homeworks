namespace HiringSystem
{
    partial class SelectType
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SelectType));
            this.label3 = new System.Windows.Forms.Label();
            this.typical = new System.Windows.Forms.Button();
            this.coursestrainee = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label3.Location = new System.Drawing.Point(12, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(796, 96);
            this.label3.TabIndex = 9;
            this.label3.Text = resources.GetString("label3.Text");
            // 
            // typical
            // 
            this.typical.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.typical.Location = new System.Drawing.Point(160, 141);
            this.typical.Name = "typical";
            this.typical.Size = new System.Drawing.Size(172, 60);
            this.typical.TabIndex = 10;
            this.typical.Text = "Typical hiring \r\nprocess";
            this.typical.UseVisualStyleBackColor = true;
            this.typical.Click += new System.EventHandler(this.typical_Click);
            // 
            // coursestrainee
            // 
            this.coursestrainee.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.coursestrainee.Location = new System.Drawing.Point(515, 141);
            this.coursestrainee.Name = "coursestrainee";
            this.coursestrainee.Size = new System.Drawing.Size(172, 60);
            this.coursestrainee.TabIndex = 11;
            this.coursestrainee.Text = "Courses trainee\r\nhiring process";
            this.coursestrainee.UseVisualStyleBackColor = true;
            this.coursestrainee.Click += new System.EventHandler(this.coursestrainee_Click);
            // 
            // SelectType
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 234);
            this.Controls.Add(this.coursestrainee);
            this.Controls.Add(this.typical);
            this.Controls.Add(this.label3);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "SelectType";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.SelectType_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button typical;
        private System.Windows.Forms.Button coursestrainee;
    }
}