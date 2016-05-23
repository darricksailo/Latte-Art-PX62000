using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConvertToBlackAndWhite
{
    public partial class MainWindow : Form
    {
        string filePath = "";
        Bitmap originalImage;
        Bitmap croppedImage;
        Bitmap scaledOImage;
        Bitmap scaledCImage;
        static int[,] bwMatrix = new int[25,25];
        String text_lookup_table;
        String text_plain_array;
        String textSelection = "";
        public static int resolution = 25;
        string scaleText = "";
        static double scale = 1;
        int scaledResolution = (int)(scale * resolution);

        public MainWindow()
        {
            InitializeComponent();
            richCodeTextBox_lookup.Visible = true;
            richCodeTextBox_plain.Visible = true;
            bwPictureBox.Visible = false;
            processedImageButton.Enabled = false;
            textButton.Enabled = false;
            originalImageButton.Enabled = false;
            saveButton.Enabled = false;
            this.Icon = Icon.ExtractAssociatedIcon(Application.ExecutablePath);
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            try
            {
                if (Form.ActiveForm.WindowState != FormWindowState.Minimized)
                {
                    // implement scaling for all UI elements
                    int widthChanged = (MainWindow.ActiveForm.Size.Width - 360);
                    int heightChanged = (Form.ActiveForm.Size.Height - 510);

                    #region 1st row of buttons

                    int row1WidthChanged = 75 + widthChanged / 4;
                    int row1HeightChanged = 35 + heightChanged / 16;
                    int row1HeightLocation = 12;

                    browseButton.Size = new System.Drawing.Size(row1WidthChanged, row1HeightChanged);
                    browseButton.Location = new System.Drawing.Point(browseButton.Location.X, row1HeightLocation);
                    browseButton.Font = new Font(browseButton.Font.Name, 8 + widthChanged / 64, browseButton.Font.Style);

                    processButton.Size = new System.Drawing.Size(row1WidthChanged, row1HeightChanged);
                    processButton.Location = new System.Drawing.Point(93 + widthChanged / 4, row1HeightLocation);
                    processButton.Font = new Font(processButton.Font.Name, 8 + widthChanged / 64, processButton.Font.Style);

                    processedImageButton.Size = new System.Drawing.Size(row1WidthChanged, row1HeightChanged);
                    processedImageButton.Location = new System.Drawing.Point(174 + (2 * widthChanged) / 4, row1HeightLocation);
                    processedImageButton.Font = new Font(processedImageButton.Font.Name, 8 + widthChanged / 64, processedImageButton.Font.Style);

                    textButton.Size = new System.Drawing.Size(row1WidthChanged, row1HeightChanged);
                    textButton.Location = new System.Drawing.Point(255 + (3 * widthChanged) / 4, row1HeightLocation);
                    textButton.Font = new Font(textButton.Font.Name, 8 + widthChanged / 64, textButton.Font.Style);
                    #endregion

                    #region 2nd row of buttons

                    int row2WidthChanged = row1WidthChanged;
                    int row2HeightChanged = row1HeightChanged;
                    int row2HeightLocation = 53 + heightChanged / 16;

                    originalImageButton.Size = new System.Drawing.Size(row2WidthChanged, row2HeightChanged);
                    originalImageButton.Location = new System.Drawing.Point(originalImageButton.Location.X, row2HeightLocation);
                    originalImageButton.Font = new Font(originalImageButton.Font.Name, 8 + widthChanged / 64, originalImageButton.Font.Style);

                    resolutionButton.Size = new System.Drawing.Size(row2WidthChanged, row2HeightChanged);
                    resolutionButton.Location = new System.Drawing.Point(93 + widthChanged / 4, row2HeightLocation);
                    resolutionButton.Font = new Font(resolutionButton.Font.Name, 8 + widthChanged / 64, resolutionButton.Font.Style);

                    saveButton.Size = new System.Drawing.Size(row2WidthChanged, row2HeightChanged);
                    saveButton.Location = new System.Drawing.Point(174 + (2 * widthChanged) / 4, row2HeightLocation);
                    saveButton.Font = new Font(saveButton.Font.Name, 8 + widthChanged / 64, saveButton.Font.Style);

                    aboutButton.Size = new System.Drawing.Size(row2WidthChanged, row2HeightChanged);
                    aboutButton.Location = new System.Drawing.Point(255 + (3 * widthChanged) / 4, row2HeightLocation);
                    aboutButton.Font = new Font(aboutButton.Font.Name, 8 + widthChanged / 64, aboutButton.Font.Style);
                    #endregion

                    #region 3rd row of UI elements
                    filePathTextBox.Size = new System.Drawing.Size(260 + widthChanged, 20);
                    filePathTextBox.Location = new System.Drawing.Point(filePathTextBox.Location.X, 94 + (2 * heightChanged) / 16);

                    scaleTextBox.Size = new System.Drawing.Size(50, 20);
                    scaleTextBox.Location = new System.Drawing.Point(280 + widthChanged, 94 + (2 * heightChanged) / 16);
                    #endregion

                    bwPictureBox.Size = new System.Drawing.Size((int)(scale * resolution) + 18, (int)(scale * resolution) + 18);
                    bwPictureBox.Location = new System.Drawing.Point(12, 120 + (2 * heightChanged) / 16);

                    richCodeTextBox_lookup.Size = new System.Drawing.Size(318 + widthChanged, 318 + (int)(0.88 * heightChanged));
                    richCodeTextBox_lookup.Location = new System.Drawing.Point(12, 120 + (2 * heightChanged) / 16);

                    richCodeTextBox_plain.Size = new System.Drawing.Size(318 + widthChanged, 318 + (int)(0.88 * heightChanged));
                    richCodeTextBox_plain.Location = new System.Drawing.Point(12, 120 + (2 * heightChanged) / 16);

                    resolutionStatusLabel.Size = new System.Drawing.Size(resolutionStatusLabel.Size.Width, 17 + heightChanged / 32);
                    resolutionStatusLabel.Font = new Font(resolutionStatusLabel.Font.Name, 9 + widthChanged / 256, resolutionStatusLabel.Font.Style);

                    progressStatusLabel.Size = new System.Drawing.Size(progressStatusLabel.Size.Width, 17 + heightChanged / 32);
                    progressStatusLabel.Font = new Font(progressStatusLabel.Font.Name, 9 + widthChanged / 256, progressStatusLabel.Font.Style);
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void browseButton_Click(object sender, EventArgs e)
        {
            try
            {
                // browse for image
                DialogResult result = browseDialog.ShowDialog();
                if (result == DialogResult.OK)
                {
                    filePath = browseDialog.FileName;
                    filePathTextBox.Text = browseDialog.FileName;
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void processButton_Click(object sender, EventArgs e)
        {
            try
            {
                Stopwatch aStopWatch = new Stopwatch();
                // only process when an image file is selected
                bool valid = false;
                if (filePath != "")
                {
                    valid = true;
                }

                if (valid)
                {
                    aStopWatch.Start();
                    richCodeTextBox_lookup.Visible = false;
                    richCodeTextBox_plain.Visible = false;
                    bwPictureBox.Visible = true;
                    int imageHeight, imageWidth;
                    int xStart, yStart;
                    progressStatusLabel.Text = "Processing...";
                    resolutionProgressStatusBar.Refresh();

                    // create an Image class data structure from the image
                    Image _image = Image.FromFile(filePath);

                    // convert Image type to a Bitmap type
                    Bitmap bt = new Bitmap(_image);

                    // find the dimensions to crop into a square
                    // look for the smaller length/width and crop to that
                    // crop to center, find starting x or y coordinate
                    if (bt.Height > bt.Width)
                    {
                        xStart = 0;
                        yStart = (bt.Height - bt.Width) / 2;
                        imageHeight = bt.Width;
                        imageWidth = bt.Width;
                    }
                    else if (bt.Width > bt.Height)
                    {
                        xStart = (bt.Width - bt.Height) / 2;
                        yStart = 0;
                        imageHeight = bt.Height;
                        imageWidth = bt.Height;
                    }
                    else
                    {
                        xStart = 0;
                        yStart = 0;
                        imageHeight = bt.Height;
                        imageWidth = bt.Width;
                    }

                    // crop image to a square with the new resolution
                    Rectangle Rect = new Rectangle(xStart, yStart, imageWidth, imageHeight);
                    croppedImage = bt.Clone(Rect, PixelFormat.DontCare);
                    originalImage = new Bitmap(croppedImage, resolution, resolution);
                    croppedImage = new Bitmap(croppedImage, resolution, resolution);

                    // assign the height and width with the new resolution
                    imageHeight = resolution;
                    imageWidth = resolution;

                    BitmapData bitmapData = croppedImage.LockBits(new Rectangle(0, 0, croppedImage.Width, croppedImage.Height), ImageLockMode.ReadWrite, croppedImage.PixelFormat);
                    // get the amount of bytes per pixel
                    int bytesPerPixel = Bitmap.GetPixelFormatSize(croppedImage.PixelFormat) / 8;
                    // get the total byte count, width 8 height
                    int byteCount = bitmapData.Stride * croppedImage.Height;
                    byte[] pixels = new byte[byteCount];
                    // create a pointer that points to the first address of the bitmapData
                    IntPtr ptrFirstPixel = bitmapData.Scan0;
                    Marshal.Copy(ptrFirstPixel, pixels, 0, pixels.Length);
                    int heightInPixels = bitmapData.Height;
                    int widthInBytes = bitmapData.Width * bytesPerPixel;

                    for (int y = 0; y < heightInPixels; y++)
                    {
                        int currentLine = y * bitmapData.Stride;
                        for (int x = 0; x < widthInBytes; x = x + bytesPerPixel)
                        {
                            int oldBlue = pixels[currentLine + x];
                            int oldGreen = pixels[currentLine + x + 1];
                            int oldRed = pixels[currentLine + x + 2];

                            // if pixel is transparent, alpha channel will equal 0
                            // interpret transparency layers as white
                            if (pixels[currentLine + x + 3] == 0)
                            {
                                bwMatrix[x / bytesPerPixel, y] = 0;
                                pixels[currentLine + x] = 0;
                                pixels[currentLine + x + 1] = 0;
                                pixels[currentLine + x + 2] = 0;
                            }
                            // convert to black and white
                            else if ((oldRed + oldGreen + oldBlue) < 575)
                            {
                                // set pixel to black
                                bwMatrix[x / bytesPerPixel, y] = 1;
                                pixels[currentLine + x] = 0;
                                pixels[currentLine + x + 1] = 0;
                                pixels[currentLine + x + 2] = 0;
                            }
                            else
                            {
                                // set pixel to white
                                bwMatrix[x / bytesPerPixel, y] = 0;
                                pixels[currentLine + x] = 255;
                                pixels[currentLine + x + 1] = 255;
                                pixels[currentLine + x + 2] = 255;
                            }

                        }
                    }
                    // copy modified bytes back
                    Marshal.Copy(pixels, 0, ptrFirstPixel, pixels.Length);
                    croppedImage.UnlockBits(bitmapData);

                    // multithreaded image processing
                    // 8 threads to work on image
                    /*int SPLIT = 8;
                    double decimalSPLIT = 8.00;
                    Bitmap[] tempImage = new Bitmap[SPLIT];
                    Rectangle[] tempRect = new Rectangle[SPLIT];
                    Thread[] convert = new Thread[SPLIT];

                    // split the picture into 8 parts
                    // imageHeight/8, round up
                    // e.g. 50 pixels / 8 parts = 6.25 pixel each parts, but it'll be 7 pixels
                    // each picture will be cut to 7 pixels in height (with the last usually being less than the rest)
                    int startCropY = 0;
                    int splitSize = (int)Math.Ceiling(imageHeight / decimalSPLIT);
                    int numberOfIncrements = splitSize;
                    int[] croppedSize = new int[8];

                    // create 8 rectangles
                    // crop the original image based on the rectangle starting coordinates and size
                    //filePathTextBox.Text = "";
                    for (int i = 0; i < SPLIT; i++)
                    {
                        croppedSize[i] = numberOfIncrements;
                        //filePathTextBox.Text = filePathTextBox.Text + startCropY + " " + (startCropY + numberOfIncrements) + " | ";
                        tempRect[i] = new Rectangle(0, startCropY, imageWidth, numberOfIncrements);
                        tempImage[i] = croppedImage.Clone(tempRect[i], PixelFormat.DontCare);
                        tempImage[i] = new Bitmap(tempImage[i], resolution, numberOfIncrements);
                        startCropY = startCropY + numberOfIncrements;
                        // ensures the last one doesn't exceed the resolution size
                        // e.g. the last part of the image starts at y = 48, but the image is only 50 pixels high
                        // so this will make sure the size will be 2px, and not 7 px
                        if (startCropY + numberOfIncrements > resolution)
                        {
                            numberOfIncrements = resolution - startCropY;
                        }
                    }

                    // create 8 thread objects
                    // for some unknown reason, the thread objects cannot be created using a for loop
                    // I get an unhandled exception for array index out of bounds even though it is not
                    convert[0] = new Thread(() => ConvertBW(tempImage[0], imageWidth, croppedSize[0], 0, croppedSize));
                    convert[1] = new Thread(() => ConvertBW(tempImage[1], imageWidth, croppedSize[1], 1, croppedSize));
                    convert[2] = new Thread(() => ConvertBW(tempImage[2], imageWidth, croppedSize[2], 2, croppedSize));
                    convert[3] = new Thread(() => ConvertBW(tempImage[3], imageWidth, croppedSize[3], 3, croppedSize));
                    convert[4] = new Thread(() => ConvertBW(tempImage[4], imageWidth, croppedSize[4], 4, croppedSize));
                    convert[5] = new Thread(() => ConvertBW(tempImage[5], imageWidth, croppedSize[5], 5, croppedSize));
                    convert[6] = new Thread(() => ConvertBW(tempImage[6], imageWidth, croppedSize[6], 6, croppedSize));
                    convert[7] = new Thread(() => ConvertBW(tempImage[7], imageWidth, croppedSize[7], 7, croppedSize));

                    // start the threads
                    for (int i = 0; i < SPLIT; i++)
                    {
                        convert[i].Start();
                    }

                    // wait for all the threads to finish executing before continuing
                    for (int i = 0; i < SPLIT; i++)
                    {
                        convert[i].Join();
                    }

                    // combine all the different pieces of the processed image into 1 image
                    Graphics g = Graphics.FromImage(croppedImage);
                    startCropY = 0;
                    for (int i = 0; i < SPLIT; i++)
                    {
                        // draw the image on the destination based on the source at the specified x and y coordinates
                        g.DrawImage(tempImage[i], 0, startCropY);
                        startCropY = startCropY + croppedSize[i];
                    }*/

                    // convert cropped image to grayscale or black and white
                    /*for (int x = 0; x < imageWidth; x++)
                    {
                        for (int y = 0; y < imageHeight; y++)
                        {
                            Color c = croppedImage.GetPixel(x, y);
                            int r = c.R;
                            int g = c.G;
                            int b = c.B;

                            // convert to grayscale
                            //int avg = (r + g + b) / 3;
                            //croppedImage.SetPixel(x, y, Color.FromArgb(avg, avg, avg));

                            // convert to black and white
                            if ((r + g + b) < 575)
                            {
                                // set pixel to black
                                bwMatrix[x, y] = 1;
                                croppedImage.SetPixel(x, y, Color.FromArgb(0, 0, 0));
                            }
                            else
                            {
                                // set pixel to white
                                bwMatrix[x, y] = 0;
                                croppedImage.SetPixel(x, y, Color.FromArgb(255, 255, 255));
                            }
                        }
                    }*/

                    // create black and white array with specified resolution
                    // output string to code text box
                    StringBuilder temp = new StringBuilder();
                    StringBuilder temp1 = new StringBuilder();
                    temp.Append("{ ");
                    for (int i = 0; i < resolution; i++)
                    {
                        temp.Append("{");
                        for (int j = 0; j < resolution; j++)
                        {
                            temp1.Append(bwMatrix[j, i]);
                            if (j < resolution - 1)
                            {
                                temp.Append(bwMatrix[j, i].ToString());
                                temp.Append(", ");
                            }
                            else
                            {
                                temp.Append(bwMatrix[j, i].ToString());
                            }
                        }
                        if (i < resolution - 1)
                        {
                            temp.Append("}, \r\n");
                        }
                        else
                        {
                            temp.Append("} ");
                        }
                    }
                    temp.Append("}");
                    temp1.Append(";!;STOP;!;");
                    text_lookup_table = temp.ToString();
                    text_plain_array = temp1.ToString();
                    richCodeTextBox_lookup.Text = text_lookup_table;
                    richCodeTextBox_plain.Text = text_plain_array;
                    textSelection = "lookup_table";

                    // create scaled images based on the scale
                    // output processed image to picture box
                    scaledResolution = (int)(scale * resolution);
                    if (scaledResolution <= 0)
                    {
                        scaledResolution = 1;
                    }
                    scaledCImage = new Bitmap(croppedImage, scaledResolution, scaledResolution);
                    scaledOImage = new Bitmap(originalImage, scaledResolution, scaledResolution);
                    bwPictureBox.Size = new System.Drawing.Size(scaledResolution + 18, scaledResolution + 18);
                    bwPictureBox.Image = scaledCImage;

                    // enable all disabled buttons
                    saveButton.Enabled = true;
                    processedImageButton.Enabled = true;
                    textButton.Enabled = true;
                    originalImageButton.Enabled = true;
                    // allow changes to scale percentage box
                    scaleTextBox.ReadOnly = false;
                    progressStatusLabel.Text = "Done";
                    
                    // dispose original image since we no longer need it
                    // this allows user to move/delete/etc file on computer without having to exit the program
                    _image.Dispose();
                    bt.Dispose();

                    aStopWatch.Stop();
                    //filePathTextBox.Text = (aStopWatch.ElapsedMilliseconds).ToString() + " milliseconds elapsed";
                }
                else
                {
                    MessageBox.Show("Please select an image.", "Error!");
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void ConvertBW(Bitmap tempImage, int imageWidth, int imageHeight, int index, int[] croppedSize)
        {
            try
            {
                int y_offset = 0;
                for (int i = 0; i < index; i++)
                {
                    y_offset += croppedSize[i];
                }

                for (int x = 0; x < imageWidth; x++)
                {
                    for (int y = 0; y < imageHeight; y++)
                    {
                        Color c = tempImage.GetPixel(x, y);
                        int r = c.R;
                        int g = c.G;
                        int b = c.B;

                        // convert to grayscale
                        //int avg = (r + g + b) / 3;
                        //tempImage.SetPixel(x, y, Color.FromArgb(avg, avg, avg));

                        // convert to black and white
                        if ((r + g + b) < 575)
                        {
                            // set pixel to black
                            bwMatrix[x, y + y_offset] = 1;
                            tempImage.SetPixel(x, y, Color.FromArgb(0, 0, 0));
                        }
                        else
                        {
                            // set pixel to white
                            bwMatrix[x, y + y_offset] = 0;
                            tempImage.SetPixel(x, y, Color.FromArgb(255, 255, 255));
                        }
                    }
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void processedImageButton_Click(object sender, EventArgs e)
        {
            try
            {
                bwPictureBox.Image = scaledCImage;
                richCodeTextBox_lookup.Visible = false;
                richCodeTextBox_plain.Visible = false;
                bwPictureBox.Visible = true;
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void textButton_Click(object sender, EventArgs e)
        {
            try
            {
                bwPictureBox.Visible = false;
                if (textSelection == "lookup_table")
                {
                    textSelection = "plain_array";
                    richCodeTextBox_lookup.Visible = true;
                    richCodeTextBox_plain.Visible = false;
                }
                else if (textSelection == "plain_array")
                {
                    textSelection = "lookup_table";
                    richCodeTextBox_plain.Visible = true;
                    richCodeTextBox_lookup.Visible = false;
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void originalImageButton_Click(object sender, EventArgs e)
        {
            try
            {
                bwPictureBox.Image = scaledOImage;
                richCodeTextBox_lookup.Visible = false;
                richCodeTextBox_plain.Visible = false;
                bwPictureBox.Visible = true;
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void resolutionButton_Click(object sender, EventArgs e)
        {
            try
            {
                ResolutionWindow resolutionWindow = new ResolutionWindow();
                resolutionWindow.ShowDialog();
                bwMatrix = new int[resolution, resolution];
                resolutionStatusLabel.Text = "Resolution: " + resolution + "x" + resolution + "px";
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            try
            {
                // save displayed image
                if (bwPictureBox.Image.Equals(scaledCImage))
                {
                    saveDialog.FileName = "BW";
                }
                else if (bwPictureBox.Image.Equals(scaledOImage))
                {
                    saveDialog.FileName = "RGB";
                }

                DialogResult result = saveDialog.ShowDialog();
                string saveFilePath = "";
                if (result == DialogResult.OK)
                {
                    saveFilePath = saveDialog.FileName;
                    if (bwPictureBox.Image.Equals(scaledCImage))
                    {
                        scaledCImage.Save(saveFilePath, ImageFormat.Jpeg);
                    }
                    else if (bwPictureBox.Image.Equals(scaledOImage))
                    {
                        scaledOImage.Save(saveFilePath, ImageFormat.Jpeg);
                    }
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void aboutButton_Click(object sender, EventArgs e)
        {
            try
            {
                AboutWindow aboutWindow = new AboutWindow();
                aboutWindow.ShowDialog();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void scaleTextBox_MouseDown(object sender, MouseEventArgs e)
        {
            try
            {
                scaleText = scaleTextBox.Text;
                scaleTextBox.SelectAll();
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

        private void scaleTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.KeyCode == Keys.Enter)
                {
                    string scaletemp = String.Empty;
                    scaletemp = scaleTextBox.Text;

                    // check if string contains the pattern of
                    // 1 or more decimal numbers, followed by 0 or 1 occurence of the % symbol
                    if (Regex.IsMatch(scaletemp, @"^\d+%?$"))
                    {
                        // if string ends with % symbol, remove it before getting the zoom scaling value
                        if (Regex.IsMatch(scaletemp, @"^\d+%"))
                        {
                            scaleTextBox.Text = scaletemp;
                            scale = Double.Parse(scaletemp.Substring(0, scaletemp.Length - 1)) / 100;
                        }
                        else
                        {
                            scaleTextBox.Text = scaletemp + "%";
                            scale = Double.Parse(scaletemp) / 100;
                        }

                        // based on the zoom scaling value, calculate the new resolution and picture box size
                        scaledResolution = (int)(scale * resolution);
                        if (scaledResolution <= 0)
                        {
                            scaledResolution = 1;
                        }

                        if (bwPictureBox.Image.Equals(scaledCImage))
                        {
                            scaledOImage = new Bitmap(originalImage, scaledResolution, scaledResolution);
                            scaledCImage = new Bitmap(croppedImage, scaledResolution, scaledResolution);
                            bwPictureBox.Size = new System.Drawing.Size(scaledResolution + 18, scaledResolution + 18);
                            bwPictureBox.Image = scaledCImage;
                        }
                        else if (bwPictureBox.Image.Equals(scaledOImage))
                        {
                            scaledOImage = new Bitmap(originalImage, scaledResolution, scaledResolution);
                            scaledCImage = new Bitmap(croppedImage, scaledResolution, scaledResolution);
                            bwPictureBox.Size = new System.Drawing.Size(scaledResolution + 18, scaledResolution + 18);
                            bwPictureBox.Image = scaledOImage;
                        }

                        scaleTextBox.SelectAll();
                    }
                    else
                    {
                        MessageBox.Show("Invalid Integer!", "Error!");
                        scaleTextBox.Text = scaleText;
                    }
                }

                if (e.Control && e.KeyCode == Keys.A)
                {
                    scaleTextBox.SelectAll();
                }
            }
            catch (Exception error)
            {
                MessageBox.Show(error.ToString());
            }
        }

    }
}
