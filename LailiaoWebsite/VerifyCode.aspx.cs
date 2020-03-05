using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Drawing;
public partial class Account_VerifyCode : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string s=Verification_Code.CreateRandomCode(4);
        Verification_Code.CreateImage(s);
        Session["CheckCode"] = s;
    }
}
