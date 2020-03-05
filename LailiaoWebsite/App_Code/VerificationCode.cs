using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Drawing;
using System.IO;

/// <summary>
/// VerificationCode 的摘要说明
/// </summary>
public  class Verification_Code
{
	public Verification_Code()
	{
		//
		// TODO: 在此处添加构造函数逻辑
		//
	}
    public static string CreateRandomCode(int CodeNum)
    {
        string str = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,1,2,3,4,5,6,7,8,9,0,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
        string[] codeChar = str.Split(',');
        string randomCode = "";
        int temp = -1;
        Random r = new Random();
        for (int i = 0; i < CodeNum; i++)
        {
            if (temp != -1)
            {
                r = new Random(i * temp * ((int)DateTime.Now.Ticks));
            }
            int t = r.Next(62);
            if (temp == t)
            {
                return CreateRandomCode(CodeNum);
            }
            temp = t;
            randomCode += codeChar[t];
        }    
        return randomCode;
    }
    public static void CreateImage(string RandomCode)
    {
        int imageWidth = (int)(RandomCode.Length * 25);
        Bitmap image = new Bitmap(imageWidth, 25);
        Graphics g = Graphics.FromImage(image);
        Random rand = new Random();
        Color[] c = { Color.Black, Color.Red, Color.DarkBlue, Color.Green, Color.Orange, Color.Brown, Color.DarkCyan, Color.Purple };
        string[] font = { "Times New Roman", "Arial"};
        g.Clear(Color.White);
        for (int i = 0; i < RandomCode.Length; i++)
        {
            int cindex = rand.Next(8);
            int findex = rand.Next(2);
            int sindex = rand.Next(14, 17);

            Font f = new Font(font[findex], sindex, FontStyle.Bold);
            Brush b = new SolidBrush(c[cindex]);
            //指定每一个字符的格式
            int ii = 4;
            if ((i + 1) % 2 == 0)
            {
                ii = 2;
            }
            g.DrawString(RandomCode.Substring(i, 1), f, b, i * 22, ii);
            //第一个参数表示显示的字符，第二、三个参数分别表示字体和颜色，
            //第四个参数表示离原点的距离（x坐标），第五个参数表示纵坐标（y坐标）            
        }

        for (int i = 0; i < 4; i++)
        {
            int x1 = rand.Next(image.Width);
            int x2 = rand.Next(image.Width);
            int y1 = rand.Next(image.Height);
            int y2 = rand.Next(image.Height);

            g.DrawLine(new Pen(Color.Silver), x1, y1, x2, y2);

        }

        for (int i = 0; i < 100; i++)
        {
            int x = rand.Next(image.Width);
            int y = rand.Next(image.Height);

            image.SetPixel(x, y, Color.FromArgb(rand.Next()));
        }
        g.DrawRectangle(new Pen(Color.Silver), 0, 0, image.Width - 1, image.Height - 1);
        System.IO.MemoryStream ms = new System.IO.MemoryStream();  
        image.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
        System.Web.HttpContext.Current.Response.ClearContent();
        System.Web.HttpContext.Current.Response.ContentType = "image/Jpeg";
        System.Web.HttpContext.Current.Response.BinaryWrite(ms.ToArray());  
        g.Dispose();
        image.Dispose();
    }
}