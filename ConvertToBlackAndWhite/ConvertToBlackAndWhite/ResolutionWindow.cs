using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConvertToBlackAndWhite
{
    public partial class ResolutionWindow : Form
    {
        public ResolutionWindow()
        {
            InitializeComponent();
            this.Icon = Icon.ExtractAssociatedIcon(Application.ExecutablePath);
        }

        private void submitButton_Click(object sender, EventArgs e)
        {
            try
            {
                string pxtemp;
                pxtemp = pxTextBox.Text;
                var match = Regex.IsMatch(pxtemp, @"^\d+$");

                if (match)
                {
                    if (Int32.Parse(pxtemp) > 2000)
                    {
                        MessageBox.Show("Please enter a smaller integer number", "Value Too Large!");
                        pxTextBox.SelectAll();
                    }
                    else
                    {
                        MainWindow.resolution = Int32.Parse(pxtemp);
                        this.Dispose();
                    }
                }
                else
                {
                    MessageBox.Show("Please enter a valid integer number", "Error!");
                    pxTextBox.SelectAll();
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void pxTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.KeyCode == Keys.Enter)
                {
                    submitButton_Click(sender, e);
                }
                else if (e.KeyCode == Keys.Escape)
                {
                    this.Dispose();
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

    }
}
