namespace HiringSystem
{
    partial class BackgroundCheck
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(BackgroundCheck));
            this.label1 = new System.Windows.Forms.Label();
            this.next = new System.Windows.Forms.Button();
            this.tableLayoutPanelResults = new System.Windows.Forms.TableLayoutPanel();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.labelCredProbl = new System.Windows.Forms.Label();
            this.labelOverall = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.labelCrimRec = new System.Windows.Forms.Label();
            this.labelPastEmpExp = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.back = new System.Windows.Forms.Button();
            this.tableLayoutPanelResults.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoEllipsis = true;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(806, 240);
            this.label1.TabIndex = 7;
            this.label1.Text = resources.GetString("label1.Text");
            // 
            // next
            // 
            this.next.Location = new System.Drawing.Point(743, 252);
            this.next.Name = "next";
            this.next.Size = new System.Drawing.Size(75, 23);
            this.next.TabIndex = 9;
            this.next.Text = "Next";
            this.next.UseVisualStyleBackColor = true;
            this.next.Click += new System.EventHandler(this.next_Click);
            // 
            // tableLayoutPanelResults
            // 
            this.tableLayoutPanelResults.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.tableLayoutPanelResults.AutoSize = true;
            this.tableLayoutPanelResults.BackColor = System.Drawing.SystemColors.Control;
            this.tableLayoutPanelResults.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tableLayoutPanelResults.ColumnCount = 2;
            this.tableLayoutPanelResults.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanelResults.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanelResults.Controls.Add(this.label5, 0, 2);
            this.tableLayoutPanelResults.Controls.Add(this.label6, 0, 0);
            this.tableLayoutPanelResults.Controls.Add(this.label3, 0, 3);
            this.tableLayoutPanelResults.Controls.Add(this.labelCredProbl, 1, 1);
            this.tableLayoutPanelResults.Controls.Add(this.labelOverall, 1, 3);
            this.tableLayoutPanelResults.Controls.Add(this.label4, 0, 1);
            this.tableLayoutPanelResults.Controls.Add(this.labelCrimRec, 1, 0);
            this.tableLayoutPanelResults.Controls.Add(this.labelPastEmpExp, 1, 2);
            this.tableLayoutPanelResults.Location = new System.Drawing.Point(126, 51);
            this.tableLayoutPanelResults.Name = "tableLayoutPanelResults";
            this.tableLayoutPanelResults.RowCount = 4;
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanelResults.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanelResults.Size = new System.Drawing.Size(585, 167);
            this.tableLayoutPanelResults.TabIndex = 21;
            this.tableLayoutPanelResults.Visible = false;
            // 
            // label5
            // 
            this.label5.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label5.Location = new System.Drawing.Point(4, 92);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(285, 21);
            this.label5.TabIndex = 17;
            this.label5.Text = "Past employers expression";
            // 
            // label6
            // 
            this.label6.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label6.Location = new System.Drawing.Point(53, 10);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(186, 21);
            this.label6.TabIndex = 18;
            this.label6.Text = "Criminal records";
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label3.Location = new System.Drawing.Point(103, 134);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 21);
            this.label3.TabIndex = 6;
            this.label3.Text = "Overall";
            // 
            // labelCredProbl
            // 
            this.labelCredProbl.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.labelCredProbl.AutoSize = true;
            this.labelCredProbl.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCredProbl.Location = new System.Drawing.Point(346, 49);
            this.labelCredProbl.Name = "labelCredProbl";
            this.labelCredProbl.Size = new System.Drawing.Size(185, 25);
            this.labelCredProbl.TabIndex = 23;
            this.labelCredProbl.Text = "Financial problems";
            // 
            // labelOverall
            // 
            this.labelOverall.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.labelOverall.AutoSize = true;
            this.labelOverall.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelOverall.Location = new System.Drawing.Point(400, 132);
            this.labelOverall.Name = "labelOverall";
            this.labelOverall.Size = new System.Drawing.Size(76, 25);
            this.labelOverall.TabIndex = 22;
            this.labelOverall.Text = "Overall";
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Courier New", 14.25F);
            this.label4.Location = new System.Drawing.Point(42, 51);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(208, 21);
            this.label4.TabIndex = 16;
            this.label4.Text = "Financial problems";
            // 
            // labelCrimRec
            // 
            this.labelCrimRec.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.labelCrimRec.AutoSize = true;
            this.labelCrimRec.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCrimRec.Location = new System.Drawing.Point(357, 8);
            this.labelCrimRec.Name = "labelCrimRec";
            this.labelCrimRec.Size = new System.Drawing.Size(162, 25);
            this.labelCrimRec.TabIndex = 25;
            this.labelCrimRec.Text = "Criminal records";
            // 
            // labelPastEmpExp
            // 
            this.labelPastEmpExp.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.labelPastEmpExp.AutoSize = true;
            this.labelPastEmpExp.Font = new System.Drawing.Font("Microsoft YaHei UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPastEmpExp.Location = new System.Drawing.Point(310, 90);
            this.labelPastEmpExp.Name = "labelPastEmpExp";
            this.labelPastEmpExp.Size = new System.Drawing.Size(256, 25);
            this.labelPastEmpExp.TabIndex = 24;
            this.labelPastEmpExp.Text = "Past employers expression";
            // 
            // label2
            // 
            this.label2.AutoEllipsis = true;
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Modern No. 20", 15.75F);
            this.label2.Location = new System.Drawing.Point(12, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(230, 24);
            this.label2.TabIndex = 22;
            this.label2.Text = "Background check results:";
            this.label2.Visible = false;
            // 
            // back
            // 
            this.back.Location = new System.Drawing.Point(13, 251);
            this.back.Name = "back";
            this.back.Size = new System.Drawing.Size(75, 23);
            this.back.TabIndex = 23;
            this.back.Text = "Back";
            this.back.UseVisualStyleBackColor = true;
            this.back.Visible = false;
            this.back.Click += new System.EventHandler(this.back_Click);
            // 
            // BackgroundCheck
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.OldLace;
            this.ClientSize = new System.Drawing.Size(836, 289);
            this.Controls.Add(this.back);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tableLayoutPanelResults);
            this.Controls.Add(this.next);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "BackgroundCheck";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Modelling of the hiring process of an IT-company";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.BackgroundCheck_FormClosing);
            this.tableLayoutPanelResults.ResumeLayout(false);
            this.tableLayoutPanelResults.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button next;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanelResults;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label labelCredProbl;
        private System.Windows.Forms.Label labelOverall;
        private System.Windows.Forms.Label labelCrimRec;
        private System.Windows.Forms.Label labelPastEmpExp;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button back;
    }
}