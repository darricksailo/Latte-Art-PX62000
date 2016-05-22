namespace ConvertToBlackAndWhite
{
    partial class MainWindow
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
            this.browseButton = new System.Windows.Forms.Button();
            this.browseDialog = new System.Windows.Forms.OpenFileDialog();
            this.filePathTextBox = new System.Windows.Forms.TextBox();
            this.processButton = new System.Windows.Forms.Button();
            this.bwPictureBox = new System.Windows.Forms.PictureBox();
            this.processedImageButton = new System.Windows.Forms.Button();
            this.textButton = new System.Windows.Forms.Button();
            this.originalImageButton = new System.Windows.Forms.Button();
            this.resolutionButton = new System.Windows.Forms.Button();
            this.aboutButton = new System.Windows.Forms.Button();
            this.resolutionProgressStatusBar = new System.Windows.Forms.StatusStrip();
            this.resolutionStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.progressStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.scaleTextBox = new System.Windows.Forms.TextBox();
            this.saveButton = new System.Windows.Forms.Button();
            this.saveDialog = new System.Windows.Forms.SaveFileDialog();
            this.richCodeTextBox_lookup = new System.Windows.Forms.RichTextBox();
            this.codeTextBox = new System.Windows.Forms.TextBox();
            this.richCodeTextBox_plain = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.bwPictureBox)).BeginInit();
            this.resolutionProgressStatusBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // browseButton
            // 
            this.browseButton.Location = new System.Drawing.Point(12, 12);
            this.browseButton.Name = "browseButton";
            this.browseButton.Size = new System.Drawing.Size(75, 35);
            this.browseButton.TabIndex = 0;
            this.browseButton.Text = "Browse...";
            this.browseButton.UseVisualStyleBackColor = true;
            this.browseButton.Click += new System.EventHandler(this.browseButton_Click);
            // 
            // browseDialog
            // 
            this.browseDialog.Filter = "All Picture Files|*.jpg;*.jpeg;*.png;*.bmp| JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg| PNG" +
    " (*.png)|*.png| Bitmap Files (*.bmp)|*.bmp";
            // 
            // filePathTextBox
            // 
            this.filePathTextBox.BackColor = System.Drawing.SystemColors.InactiveBorder;
            this.filePathTextBox.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.filePathTextBox.Location = new System.Drawing.Point(12, 94);
            this.filePathTextBox.Name = "filePathTextBox";
            this.filePathTextBox.ReadOnly = true;
            this.filePathTextBox.Size = new System.Drawing.Size(260, 20);
            this.filePathTextBox.TabIndex = 1;
            this.filePathTextBox.WordWrap = false;
            // 
            // processButton
            // 
            this.processButton.Location = new System.Drawing.Point(93, 12);
            this.processButton.Name = "processButton";
            this.processButton.Size = new System.Drawing.Size(75, 35);
            this.processButton.TabIndex = 2;
            this.processButton.Text = "Process";
            this.processButton.UseVisualStyleBackColor = true;
            this.processButton.Click += new System.EventHandler(this.processButton_Click);
            // 
            // bwPictureBox
            // 
            this.bwPictureBox.Location = new System.Drawing.Point(12, 120);
            this.bwPictureBox.Name = "bwPictureBox";
            this.bwPictureBox.Size = new System.Drawing.Size(58, 58);
            this.bwPictureBox.TabIndex = 3;
            this.bwPictureBox.TabStop = false;
            // 
            // processedImageButton
            // 
            this.processedImageButton.Location = new System.Drawing.Point(174, 12);
            this.processedImageButton.Name = "processedImageButton";
            this.processedImageButton.Size = new System.Drawing.Size(75, 35);
            this.processedImageButton.TabIndex = 4;
            this.processedImageButton.Text = "Processed Image";
            this.processedImageButton.UseVisualStyleBackColor = true;
            this.processedImageButton.Click += new System.EventHandler(this.processedImageButton_Click);
            // 
            // textButton
            // 
            this.textButton.Location = new System.Drawing.Point(255, 12);
            this.textButton.Name = "textButton";
            this.textButton.Size = new System.Drawing.Size(75, 35);
            this.textButton.TabIndex = 5;
            this.textButton.Text = "Text";
            this.textButton.UseVisualStyleBackColor = true;
            this.textButton.Click += new System.EventHandler(this.textButton_Click);
            // 
            // originalImageButton
            // 
            this.originalImageButton.Location = new System.Drawing.Point(12, 53);
            this.originalImageButton.Name = "originalImageButton";
            this.originalImageButton.Size = new System.Drawing.Size(75, 35);
            this.originalImageButton.TabIndex = 7;
            this.originalImageButton.Text = "Original Image";
            this.originalImageButton.UseVisualStyleBackColor = true;
            this.originalImageButton.Click += new System.EventHandler(this.originalImageButton_Click);
            // 
            // resolutionButton
            // 
            this.resolutionButton.Location = new System.Drawing.Point(93, 53);
            this.resolutionButton.Name = "resolutionButton";
            this.resolutionButton.Size = new System.Drawing.Size(75, 35);
            this.resolutionButton.TabIndex = 8;
            this.resolutionButton.Text = "Resolution";
            this.resolutionButton.UseVisualStyleBackColor = true;
            this.resolutionButton.Click += new System.EventHandler(this.resolutionButton_Click);
            // 
            // aboutButton
            // 
            this.aboutButton.Location = new System.Drawing.Point(255, 53);
            this.aboutButton.Name = "aboutButton";
            this.aboutButton.Size = new System.Drawing.Size(75, 35);
            this.aboutButton.TabIndex = 10;
            this.aboutButton.Text = "About";
            this.aboutButton.UseVisualStyleBackColor = true;
            this.aboutButton.Click += new System.EventHandler(this.aboutButton_Click);
            // 
            // resolutionProgressStatusBar
            // 
            this.resolutionProgressStatusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.resolutionStatusLabel,
            this.toolStripStatusLabel1,
            this.progressStatusLabel});
            this.resolutionProgressStatusBar.Location = new System.Drawing.Point(0, 450);
            this.resolutionProgressStatusBar.Name = "resolutionProgressStatusBar";
            this.resolutionProgressStatusBar.Size = new System.Drawing.Size(344, 22);
            this.resolutionProgressStatusBar.TabIndex = 11;
            // 
            // resolutionStatusLabel
            // 
            this.resolutionStatusLabel.Name = "resolutionStatusLabel";
            this.resolutionStatusLabel.Size = new System.Drawing.Size(110, 17);
            this.resolutionStatusLabel.Text = "Resolution: 25x25px";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(193, 17);
            this.toolStripStatusLabel1.Spring = true;
            // 
            // progressStatusLabel
            // 
            this.progressStatusLabel.Name = "progressStatusLabel";
            this.progressStatusLabel.Size = new System.Drawing.Size(26, 17);
            this.progressStatusLabel.Text = "Idle";
            // 
            // scaleTextBox
            // 
            this.scaleTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.scaleTextBox.Location = new System.Drawing.Point(280, 94);
            this.scaleTextBox.Name = "scaleTextBox";
            this.scaleTextBox.ReadOnly = true;
            this.scaleTextBox.Size = new System.Drawing.Size(50, 20);
            this.scaleTextBox.TabIndex = 12;
            this.scaleTextBox.Text = "100%";
            this.scaleTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.scaleTextBox.WordWrap = false;
            this.scaleTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.scaleTextBox_KeyDown);
            this.scaleTextBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.scaleTextBox_MouseDown);
            // 
            // saveButton
            // 
            this.saveButton.Location = new System.Drawing.Point(172, 53);
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(75, 35);
            this.saveButton.TabIndex = 13;
            this.saveButton.Text = "Save...";
            this.saveButton.UseVisualStyleBackColor = true;
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // saveDialog
            // 
            this.saveDialog.Filter = "JPEG|*.jpg";
            // 
            // richCodeTextBox_lookup
            // 
            this.richCodeTextBox_lookup.BackColor = System.Drawing.SystemColors.InactiveBorder;
            this.richCodeTextBox_lookup.Location = new System.Drawing.Point(12, 120);
            this.richCodeTextBox_lookup.Name = "richCodeTextBox_lookup";
            this.richCodeTextBox_lookup.ReadOnly = true;
            this.richCodeTextBox_lookup.Size = new System.Drawing.Size(318, 318);
            this.richCodeTextBox_lookup.TabIndex = 14;
            this.richCodeTextBox_lookup.Text = "";
            this.richCodeTextBox_lookup.WordWrap = false;
            // 
            // codeTextBox
            // 
            this.codeTextBox.BackColor = System.Drawing.SystemColors.InactiveBorder;
            this.codeTextBox.Location = new System.Drawing.Point(12, 120);
            this.codeTextBox.Multiline = true;
            this.codeTextBox.Name = "codeTextBox";
            this.codeTextBox.ReadOnly = true;
            this.codeTextBox.Size = new System.Drawing.Size(318, 318);
            this.codeTextBox.TabIndex = 6;
            this.codeTextBox.Visible = false;
            this.codeTextBox.WordWrap = false;
            // 
            // richCodeTextBox_plain
            // 
            this.richCodeTextBox_plain.BackColor = System.Drawing.SystemColors.InactiveBorder;
            this.richCodeTextBox_plain.Location = new System.Drawing.Point(12, 120);
            this.richCodeTextBox_plain.Name = "richCodeTextBox_plain";
            this.richCodeTextBox_plain.ReadOnly = true;
            this.richCodeTextBox_plain.Size = new System.Drawing.Size(318, 318);
            this.richCodeTextBox_plain.TabIndex = 15;
            this.richCodeTextBox_plain.Text = "";
            this.richCodeTextBox_plain.WordWrap = false;
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 472);
            this.Controls.Add(this.resolutionProgressStatusBar);
            this.Controls.Add(this.saveButton);
            this.Controls.Add(this.aboutButton);
            this.Controls.Add(this.resolutionButton);
            this.Controls.Add(this.originalImageButton);
            this.Controls.Add(this.textButton);
            this.Controls.Add(this.processedImageButton);
            this.Controls.Add(this.processButton);
            this.Controls.Add(this.filePathTextBox);
            this.Controls.Add(this.browseButton);
            this.Controls.Add(this.bwPictureBox);
            this.Controls.Add(this.scaleTextBox);
            this.Controls.Add(this.richCodeTextBox_lookup);
            this.Controls.Add(this.codeTextBox);
            this.Controls.Add(this.richCodeTextBox_plain);
            this.MinimumSize = new System.Drawing.Size(360, 510);
            this.Name = "MainWindow";
            this.Text = "Convert Image to Black & White";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.bwPictureBox)).EndInit();
            this.resolutionProgressStatusBar.ResumeLayout(false);
            this.resolutionProgressStatusBar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button browseButton;
        private System.Windows.Forms.OpenFileDialog browseDialog;
        private System.Windows.Forms.TextBox filePathTextBox;
        private System.Windows.Forms.Button processButton;
        private System.Windows.Forms.PictureBox bwPictureBox;
        private System.Windows.Forms.Button processedImageButton;
        private System.Windows.Forms.Button textButton;
        private System.Windows.Forms.Button originalImageButton;
        private System.Windows.Forms.Button resolutionButton;
        private System.Windows.Forms.Button aboutButton;
        private System.Windows.Forms.StatusStrip resolutionProgressStatusBar;
        private System.Windows.Forms.ToolStripStatusLabel resolutionStatusLabel;
        private System.Windows.Forms.TextBox scaleTextBox;
        private System.Windows.Forms.Button saveButton;
        private System.Windows.Forms.SaveFileDialog saveDialog;
        private System.Windows.Forms.RichTextBox richCodeTextBox_lookup;
        private System.Windows.Forms.TextBox codeTextBox;
        private System.Windows.Forms.ToolStripStatusLabel progressStatusLabel;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.RichTextBox richCodeTextBox_plain;

    }
}

