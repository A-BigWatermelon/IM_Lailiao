using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;
using System.Web.Security;
/// <summary>
/// Users 的摘要说明
/// </summary>
public class Users
{
    private string userID;
    private string email;
    private string phone;
    private string password;
    private int rank;
    private int bonus;
    public Users()
    {
        //
        // TODO: 在此处添加构造函数逻辑
        //
    }
    public Users(string userID, string email, string phone, string password, int rank, int bonus)
    {
        this.userID = userID;
        this.email = email;
        this.phone = phone;
        this.password = password;
        this.rank = rank;
        this.bonus = bonus;
    }
    public static String emailRegister(string email, string password)
    {
        DBHelper db = new DBHelper();
        string sql;
        sql = "INSERT tbl_userinfo (nickname,password) VALUES('" + email + "','" + password + "') SELECT @@IDENTITY";
            SqlDataReader rdr = db.RunProcGetReader(sql);
            if (rdr.Read())
            {
                sql = rdr.GetValue(0).ToString();
            }
            return sql;
    }
    
    //public static bool cardRegister(string cardNum, string password)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT * FROM tbl_cust_card WHERE cardNumber = '" + cardNum + "'";
    //    if (!db.ExistDate(sql))
    //    {
    //        sql = "INSERT tbl_cust_info (password) VALUES('" + password + "') INSERT tbl_cust_card VALUES('" + cardNum + "',@@IDENTITY) "
    //           + "INSERT INTO tbl_cust_rank SELECT customerID,'1','0' FROM tbl_cust_card WHERE cardNumber ='" + cardNum + "'";
    //        db.RunProc(sql);
    //        return true;
    //    }
    //    else
    //        return false;
    //}
    //public static bool cardRegister(string cardNum, string password, string email)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT * FROM tbl_cust_card WHERE cardNumber = '" + cardNum + "'";
    //    if (!db.ExistDate(sql))
    //    {
    //        sql = "SELECT * FROM tbl_cust_email WHERE email = '" + email + "'";
    //        if (!db.ExistDate(sql))
    //        {
    //            sql = "INSERT tbl_cust_info (password) VALUES('" + password + "') INSERT tbl_cust_card VALUES('" + cardNum + "',@@IDENTITY) "
    //               + "INSERT INTO tbl_cust_rank SELECT customerID,'1','0' FROM tbl_cust_card WHERE cardNumber ='" + cardNum + "'"
    //               + "INSERT INTO tbl_cust_email SELECT '" + email + "',customerID FROM tbl_cust_card WHERE cardNumber ='" + cardNum + "'";
    //            db.RunProc(sql);
    //            return true;
    //        }
    //        else
    //            return false;
    //    }
    //    else
    //        return false;
    //}
    //public static bool phoneRegister(string phone, string password)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT * FROM tbl_cust_phone WHERE phone = '" + phone + "'";
    //    if (!db.ExistDate(sql))
    //    {
    //        sql = "INSERT tbl_cust_info (password) VALUES('" + password + "') INSERT tbl_cust_phone VALUES('" + phone + "',@@IDENTITY) "
    //            + "INSERT INTO tbl_cust_rank SELECT customerID,'1','0' FROM tbl_cust_phone WHERE phone ='" + phone + "'";
    //        db.RunProc(sql);
    //        return true;
    //    }
    //    else
    //        return false;
    //}
    //public static bool phoneRegister(string phone, string password, string email)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT * FROM tbl_cust_phone WHERE phone = '" + phone + "'";
    //    if (!db.ExistDate(sql))
    //    {
    //        sql = "SELECT * FROM tbl_cust_email WHERE email = '" + email + "'";
    //        if (!db.ExistDate(sql))
    //        {
    //            sql = "INSERT tbl_cust_info (password) VALUES('" + password + "') INSERT tbl_cust_phone VALUES('" + phone + "',@@IDENTITY) "
    //                + "INSERT INTO tbl_cust_rank SELECT customerID,'1','0' FROM tbl_cust_phone WHERE phone ='" + phone + "' "
    //                + "INSERT INTO tbl_cust_email SELECT '" + email + "',customerID FROM tbl_cust_phone WHERE phone ='" + phone + "'";
    //            db.RunProc(sql);
    //            return true;
    //        }
    //        else
    //            return false;
    //    }
    //    else
    //        return false;
    //}
    //public static bool emailLogin(string email, string password)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT customerID FROM tbl_cust_email WHERE email = '" + email + "'";
    //    if (db.ExistDate(sql))
    //    {
    //        sql = "SELECT * FROM tbl_cust_info WHERE password = '" + password + "' AND customerID IN (SELECT customerID FROM tbl_cust_email WHERE email ='" + email + "')";

    //        SqlDataReader rdr = db.RunProcGetReader(sql);
    //        while (rdr.Read())
    //        {
    //            FormsAuthenticationTicket authTicket;
    //            string id = Convert.ToString(rdr["customerID"]);
    //            if (id == "1")
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "admin", "/");
    //            }
    //            else
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "customer", "/");
    //            }
    //            string encryptedTicket = FormsAuthentication.Encrypt(authTicket);
    //            HttpCookie authCookie = new HttpCookie(FormsAuthentication.FormsCookieName, encryptedTicket);
    //            System.Web.HttpContext.Current.Response.Cookies.Add(authCookie);
    //            return true;
    //        }
    //        return false;
    //    }
    //    else
    //        return false;
    //}
    //public static bool phoneLogin(string phone, string password)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT customerID FROM tbl_cust_phone WHERE phone = '" + phone + "'";
    //    if (db.ExistDate(sql))
    //    {
    //        sql = "SELECT * FROM tbl_cust_info WHERE password = '" + password + "' AND customerID IN (SELECT customerID FROM tbl_cust_phone WHERE phone ='" + phone + "')";
    //        SqlDataReader rdr = db.RunProcGetReader(sql);
    //        while (rdr.Read())
    //        {
    //            FormsAuthenticationTicket authTicket;
    //            string id = Convert.ToString(rdr["customerID"]);
    //            if (id == "1")
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "admin", "/");
    //            }
    //            else
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "customer", "/");
    //            }
    //            string encryptedTicket = FormsAuthentication.Encrypt(authTicket);
    //            HttpCookie authCookie = new HttpCookie(FormsAuthentication.FormsCookieName, encryptedTicket);
    //            System.Web.HttpContext.Current.Response.Cookies.Add(authCookie);
    //            return true;
    //        }
    //        return false;
    //    }
    //    else
    //        return false;
    //}
    //public static bool cardLogin(string cardNum, string password)
    //{
    //    DBHelper db = new DBHelper();
    //    string sql = "SELECT customerID FROM tbl_cust_card WHERE cardNumber = '" + cardNum + "'";
    //    if (db.ExistDate(sql))
    //    {
    //        sql = "SELECT * FROM tbl_cust_info WHERE password = '" + password + "' AND customerID IN (SELECT customerID FROM tbl_cust_card WHERE cardNumber ='" + cardNum + "')";
    //        SqlDataReader rdr = db.RunProcGetReader(sql);
    //        while (rdr.Read())
    //        {
    //            FormsAuthenticationTicket authTicket;
    //            string id = Convert.ToString(rdr["customerID"]);
    //            if (id == "1")
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "admin", "/");
    //            }
    //            else
    //            {
    //                authTicket = new FormsAuthenticationTicket(1, id, DateTime.Now, DateTime.Now.AddMinutes(30), true, "customer", "/");
    //            }
    //            string encryptedTicket = FormsAuthentication.Encrypt(authTicket);
    //            HttpCookie authCookie = new HttpCookie(FormsAuthentication.FormsCookieName, encryptedTicket);
    //            System.Web.HttpContext.Current.Response.Cookies.Add(authCookie);
    //            return true;
    //        }
    //        return false;
    //    }
    //    else
    //        return false;
    //}
    //public void getUser()
    //{
    //    DBHelper db=new DBHelper();
    //    this.userID = HttpContext.Current.User.Identity.Name;
    //    string sql = "SELECT * FROM tbl_cust_rank WHERE customerID = '"+this.userID+"'";
    //    SqlDataReader rdr = db.RunProcGetReader(sql);
    //    while(rdr.Read())
    //    {
    //        this.rank = Convert.ToInt32(rdr["rank"]);
    //        this.bonus = Convert.ToInt32(rdr["lastYearBonus"]);
    //    }
    //    sql = "SELECT email FROM tbl_cust_email WHERE customerID = '" + this.userID + "'";
    //    rdr = db.RunProcGetReader(sql);
    //    if (rdr.Read())
    //        this.email = Convert.ToString(rdr["email"]);
    //    else
    //        this.email = "";
    //    sql = "SELECT phone FROM tbl_cust_phone WHERE customerID = '" + this.userID + "'";
    //    rdr = db.RunProcGetReader(sql);
    //    if (rdr.Read())
    //        this.phone = Convert.ToString(rdr["phone"]);
    //    else
    //        this.phone = "";
    //    return;
    //}
    //public static string getID()
    //{
    //    return HttpContext.Current.User.Identity.Name;
    //}
    //public string getUserID()
    //{
    //    return this.userID;
    //}
    //public string getEmail()
    //{
    //    return this.email;
    //}
    //public string getPhone()
    //{
    //    return this.phone;
    //}
    //public int getRank()
    //{
    //    return this.rank;
    //}
    //public int getBonus()
    //{
    //    return this.bonus;
    //}
    //public static bool isAdmin()
    //{
    //    if (HttpContext.Current.User.IsInRole("admin"))
    //        return true;
    //    else
    //        return false;
    //}
    //public static string getCount()
    //{
    //    DBHelper db = new DBHelper();
    //    string str = "SELECT COUNT(*) FROM tbl_cust_info";
    //    SqlDataReader rdr = db.RunProcGetReader(str);
    //    while (rdr.Read())
    //    {
    //       return Convert.ToString(rdr[0]);
    //    }
    //    return "";
    //}
}