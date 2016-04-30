using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConvertToBlackAndWhite
{
    public partial class AboutWindow : Form
    {
        string[] about1 = new string[6];
        StringBuilder about = new StringBuilder();
        public AboutWindow()
        {
            InitializeComponent();
            this.Icon = Icon.ExtractAssociatedIcon(Application.ExecutablePath);
            this.showdescription();
        }

        private void showdescription()
        {
            about1[5] = "v1.3.1\t04/30/16\r\n\u2022 Added try-catch statements to hopefully prevent all unhandled exceptions\r\n\r\n";
            about1[4] = "v1.3.0\t02/19/16\r\n\u2022 Completely revamped how image processing is done\r\n\u2022 Image processing is up to 7 times faster!\r\n\u2022 Total run time is up to 3 times faster\r\n\u2022 Removed multithreading image processing\r\n\u2022 Fixed a bug where saving an image and trying to process the same image again would cause an unhandled exception\r\n\u2022 Changed version numbers from 1.0.x to 1.x to indicate versions with significant improvements\r\n\r\n";
            about1[3] = "v1.2.0\t02/17/16\r\n\u2022 Fixed an unhandled exception error when minimizing the window due to GUI scaling implementation\r\n\u2022 Significant speed improvements:\r\n\t\u2022 Multithreaded image processing!\r\n\t\u2022 No more delay when rendering the text\r\n\tbox!\r\n\u2022 Changed text box background color to a tinted white color for those that are read-only\r\n\u2022 Properly disabled word wrapping\r\n\r\n";
            about1[2] = "v1.1.1\t02/13/16\r\n\u2022 Further improved text box rendering time\r\n\r\n";
            about1[1] = "v1.1.0\t02/13/16\r\n\u2022 Major user friendly improvements!\r\n\u2022 New features added:\r\n\t\u2022 GUI scaling\r\n\t\u2022 View original image\r\n\t\u2022 Adjust output resolution\r\n\t\u2022 Save output image\r\n\t\u2022 About/Change Log page\r\n\t\u2022 Zoom output image\r\n\u2022 Bug fixes for known unhandled exceptions\r\n\u2022 Significantly improved text box rendering time\r\n\u2022 Added status bar to show output resolution and current status of the program\r\n\u2022 Decreased program size\r\n\r\n";      //1.0.1
            about1[0] = "v1.0\t02/10/16\r\n\u2022 Initial Release";         //1.0
            
            for (int i = about1.Length - 1; i >= 0; i--)
            {
                about.Append(about1[i]);
            }
            
            changeLog.Text = about.ToString();
            changeLog.Select(0, 0);
        }

        private void changeLog_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                this.Dispose();
            }

            if (e.Control && e.KeyCode == Keys.A)
            {
                changeLog.SelectAll();
            }
        }
    }
}
