using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Account_Register : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void CreateUserButton_Click(object sender, EventArgs e)
    {
        if (this.VerificationCode.Text.ToUpper() == Session["CheckCode"].ToString().ToUpper())
        {
            String id = Users.emailRegister(this.Email.Text, this.Password.Text);
            {
                this.ErrorMessage.CssClass = "detailNotification";
                ErrorMessage.Text = "您已经注册成功，您的帐号是"+id+",请到登录页登录";
                this.ErrorMessage.Visible = true;
            }
        }
        else
        {
            this.ErrorMessage.CssClass = "failureNotification";
            ErrorMessage.Text = "验证码错误";
            this.ErrorMessage.Visible = true;
        }
    }
}