namespace ConvertToBlackAndWhite
{
    partial class ResolutionWindow
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
            this.resolutionLabel = new System.Windows.Forms.Label();
            this.pxTextBox = new System.Windows.Forms.TextBox();
            this.pxLabel = new System.Windows.Forms.Label();
            this.submitButton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // resolutionLabel
            // 
            this.resolutionLabel.AutoSize = true;
            this.resolutionLabel.Location = new System.Drawing.Point(12, 12);
            this.resolutionLabel.Name = "resolutionLabel";
            this.resolutionLabel.Size = new System.Drawing.Size(99, 13);
            this.resolutionLabel.TabIndex = 0;
            this.resolutionLabel.Text = "Desired Resolution:";
            // 
            // pxTextBox
            // 
            this.pxTextBox.Location = new System.Drawing.Point(117, 9);
            this.pxTextBox.Name = "pxTextBox";
            this.pxTextBox.Size = new System.Drawing.Size(50, 20);
            this.pxTextBox.TabIndex = 1;
            this.pxTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.pxTextBox_KeyDown);
            // 
            // pxLabel
            // 
            this.pxLabel.AutoSize = true;
            this.pxLabel.Location = new System.Drawing.Point(170, 12);
            this.pxLabel.Name = "pxLabel";
            this.pxLabel.Size = new System.Drawing.Size(18, 13);
            this.pxLabel.TabIndex = 2;
            this.pxLabel.Text = "px";
            // 
            // submitButton
            // 
            this.submitButton.Location = new System.Drawing.Point(12, 37);
            this.submitButton.Name = "submitButton";
            this.submitButton.Size = new System.Drawing.Size(75, 23);
            this.submitButton.TabIndex = 3;
            this.submitButton.Text = "Submit";
            this.submitButton.UseVisualStyleBackColor = true;
            this.submitButton.Click += new System.EventHandler(this.submitButton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.Location = new System.Drawing.Point(113, 37);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(75, 23);
            this.cancelButton.TabIndex = 4;
            this.cancelButton.Text = "Cancel";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // ResolutionWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(209, 71);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.submitButton);
            this.Controls.Add(this.pxLabel);
            this.Controls.Add(this.pxTextBox);
            this.Controls.Add(this.resolutionLabel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(225, 105);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(225, 105);
            this.Name = "ResolutionWindow";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Change Output Resolution";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label resolutionLabel;
        private System.Windows.Forms.TextBox pxTextBox;
        private System.Windows.Forms.Label pxLabel;
        private System.Windows.Forms.Button submitButton;
        private System.Windows.Forms.Button cancelButton;
    }
}