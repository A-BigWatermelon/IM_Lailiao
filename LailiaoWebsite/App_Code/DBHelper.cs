using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;
/// <summary>
/// DB 的摘要说明
/// </summary>
public class DBHelper
{
    private string ConnStr = null;
    public DBHelper()
    {
        //
        // TODO: 在此处添加构造函数逻辑
        ConnStr = System.Web.Configuration.WebConfigurationManager.ConnectionStrings["connectionString"].ToString();
        //
    }
    public DBHelper(string Str)
    {
        try
        {
            this.ConnStr = Str;
        }
        catch (Exception ex)
        {
            throw ex;
        }
    }
    public string constr()
    {
        return System.Web.Configuration.WebConfigurationManager.ConnectionStrings["connectionString"].ToString();
    }
    public static SqlConnection CreateCon()
    {

        return new SqlConnection(System.Web.Configuration.WebConfigurationManager.ConnectionStrings["connectionString"].ToString());
    }

    /// <summary> 
    /// 返回connection对象 
    /// </summary> 
    /// <returns></returns> 
    public SqlConnection ReturnConn()
    {
        SqlConnection Conn = new SqlConnection(ConnStr);
        Conn.Open();
        return Conn;
    }
    public void Dispose(SqlConnection Conn)
    {
        if (Conn != null)
        {
            Conn.Close();
            Conn.Dispose();
        }
        GC.Collect();
    }
    /// <summary> 
    /// 运行SQL语句 
    /// </summary> 
    /// <param name="SQL"></param> 
    public void RunProc(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlCommand Cmd;
        Cmd = CreateCmd(SQL, Conn);
        try
        {
            Cmd.ExecuteNonQuery();
        }
        catch (Exception ex)
        {
            string exm = ex.Message;
            throw new Exception(SQL);
        }
        Dispose(Conn);
        return;
    }

    /// <summary> 
    /// 运行SQL语句返回DataReader 
    /// </summary> 
    /// <param name="SQL"></param> 
    /// <returns>SqlDataReader对象.</returns> 
    public SqlDataReader RunProcGetReader(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlCommand Cmd;
        Cmd = CreateCmd(SQL, Conn);
        SqlDataReader Dr;
        try
        {
            Dr = Cmd.ExecuteReader(CommandBehavior.Default);
        }
        catch
        {
            throw new Exception(SQL);
        }
        //Dispose(Conn); 
        return Dr;
    }

    /// <summary> 
    /// 生成Command对象 
    /// </summary> 
    /// <param name="SQL"></param> 
    /// <param name="Conn"></param> 
    /// <returns></returns> 
    public SqlCommand CreateCmd(string SQL, SqlConnection Conn)
    {
        SqlCommand Cmd;
        Cmd = new SqlCommand(SQL, Conn);
        return Cmd;
    }

    /// <summary> 
    /// 生成Command对象 
    /// </summary> 
    /// <param name="SQL"></param> 
    /// <returns></returns> 
    public SqlCommand CreateCmd(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlCommand Cmd;
        Cmd = new SqlCommand(SQL, Conn);
        return Cmd;
    }

    /// <summary> 
    /// 返回adapter对象 
    /// </summary> 
    /// <param name="SQL"></param> 
    /// <param name="Conn"></param> 
    /// <returns></returns> 
    public SqlDataAdapter CreateDa(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlDataAdapter Da;
        Da = new SqlDataAdapter(SQL, Conn);
        return Da;
    }

    /// <summary> 
    /// 运行SQL语句,返回DataSet对象 
    /// </summary> 
    /// <param name="procName">SQL语句</param> 
    /// <param name="prams">DataSet对象</param> 
    public DataSet RunProc(string SQL, DataSet Ds)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlDataAdapter Da;
        //Da = CreateDa(SQL, Conn); 
        Da = new SqlDataAdapter(SQL, Conn);
        try
        {
            Da.Fill(Ds);
        }
        catch (Exception Err)
        {
            throw Err;
        }
        Dispose(Conn);
        return Ds;
    }

    /// <summary> 
    /// 运行SQL语句,返回DataSet对象 
    /// </summary> 
    /// <param name="procName">SQL语句</param> 
    /// <param name="prams">DataSet对象</param> 
    /// <param name="dataReader">表名</param> 
    public DataSet RunProc(string SQL, DataSet Ds, string tablename)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlDataAdapter Da;
        Da = CreateDa(SQL);
        try
        {
            Da.Fill(Ds, tablename);
        }
        catch (Exception Ex)
        {
            throw Ex;
        }
        Dispose(Conn);
        return Ds;
    }

    /// <summary> 
    /// 运行SQL语句,返回DataSet对象 
    /// </summary> 
    /// <param name="procName">SQL语句</param> 
    /// <param name="prams">DataSet对象</param> 
    /// <param name="dataReader">表名</param> 
    public DataSet RunProc(string SQL, DataSet Ds, int StartIndex, int PageSize, string tablename)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlDataAdapter Da;
        Da = CreateDa(SQL);
        try
        {
            Da.Fill(Ds, StartIndex, PageSize, tablename);
        }
        catch (Exception Ex)
        {
            throw Ex;
        }
        Dispose(Conn);
        return Ds;
    }

    /// <summary> 
    /// 检验是否存在数据 
    /// </summary> 
    /// <returns></returns> 
    public bool ExistDate(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlDataReader Dr;
        Dr = CreateCmd(SQL, Conn).ExecuteReader();
        if (Dr.Read())
        {
            Dispose(Conn);
            return true;
        }
        else
        {
            Dispose(Conn);
            return false;
        }
    }

    /// <summary> 
    /// 返回SQL语句执行结果的第一行第一列 
    /// </summary> 
    /// <returns>字符串</returns> 
    public string ReturnValue(string SQL)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        string result;
        SqlDataReader Dr;
        try
        {
            Dr = CreateCmd(SQL, Conn).ExecuteReader();
            if (Dr.Read())
            {
                result = Dr[0].ToString();
                Dr.Close();
            }
            else
            {
                result = "";
                Dr.Close();
            }
        }
        catch
        {
            throw new Exception(SQL);
        }
        Dispose(Conn);
        return result;
    }

    /// <summary> 
    /// 返回SQL语句第一列,第ColumnI列, 
    /// </summary> 
    /// <returns>字符串</returns> 
    public string ReturnValue(string SQL, int ColumnI)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        string result;
        SqlDataReader Dr;
        try
        {
            Dr = CreateCmd(SQL, Conn).ExecuteReader();
        }
        catch
        {
            throw new Exception(SQL);
        }
        if (Dr.Read())
        {
            result = Dr[ColumnI].ToString();
        }
        else
        {
            result = "";
        }
        Dr.Close();
        Dispose(Conn);
        return result;
    }

    /// <summary> 
    /// 生成一个存储过程使用的sqlcommand. 
    /// </summary> 
    /// <param name="procName">存储过程名.</param> 
    /// <param name="prams">存储过程入参数组.</param> 
    /// <returns>sqlcommand对象.</returns> 
    public SqlCommand CreateCmd(string procName, SqlParameter[] prams)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlCommand Cmd = new SqlCommand(procName, Conn);
        Cmd.CommandType = CommandType.StoredProcedure;
        if (prams != null)
        {
            foreach (SqlParameter parameter in prams)
            {
                if (parameter != null)
                {
                    Cmd.Parameters.Add(parameter);
                }
            }
        }
        return Cmd;
    }

    /// <summary> 
    /// 为存储过程生成一个SqlCommand对象 
    /// </summary> 
    /// <param name="procName">存储过程名</param> 
    /// <param name="prams">存储过程参数</param> 
    /// <returns>SqlCommand对象</returns> 
    private SqlCommand CreateCmd(string procName, SqlParameter[] prams, SqlDataReader Dr)
    {
        SqlConnection Conn;
        Conn = new SqlConnection(ConnStr);
        Conn.Open();
        SqlCommand Cmd = new SqlCommand(procName, Conn);
        Cmd.CommandType = CommandType.StoredProcedure;
        if (prams != null)
        {
            foreach (SqlParameter parameter in prams)
                Cmd.Parameters.Add(parameter);
        }
        Cmd.Parameters.Add(
        new SqlParameter("ReturnValue", SqlDbType.Int, 4,
        ParameterDirection.ReturnValue, false, 0, 0,
        string.Empty, DataRowVersion.Default, null));

        return Cmd;
    }

    /// <summary> 
    /// 运行存储过程,返回. 
    /// </summary> 
    /// <param name="procName">存储过程名</param> 
    /// <param name="prams">存储过程参数</param> 
    /// <param name="dataReader">SqlDataReader对象</param> 
    public void RunProc(string procName, SqlParameter[] prams, SqlDataReader Dr)
    {

        SqlCommand Cmd = CreateCmd(procName, prams, Dr);
        Dr = Cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
        return;
    }

    /// <summary> 
    /// 运行存储过程,返回. 
    /// </summary> 
    /// <param name="procName">存储过程名</param> 
    /// <param name="prams">存储过程参数</param> 
    public string RunProc(string procName, SqlParameter[] prams)
    {
        SqlDataReader Dr;
        SqlCommand Cmd = CreateCmd(procName, prams);
        Dr = Cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
        if (Dr.Read())
        {
            return Dr.GetValue(0).ToString();
        }
        else
        {
            return "";
        }
    }

    /// <summary> 
    /// 运行存储过程,返回dataset. 
    /// </summary> 
    /// <param name="procName">存储过程名.</param> 
    /// <param name="prams">存储过程入参数组.</param> 
    /// <returns>dataset对象.</returns> 
    public DataSet RunProc(string procName, SqlParameter[] prams, DataSet Ds)
    {
        SqlCommand Cmd = CreateCmd(procName, prams);
        SqlDataAdapter Da = new SqlDataAdapter(Cmd);
        try
        {
            Da.Fill(Ds);
        }
        catch (Exception Ex)
        {
            throw Ex;
        }
        return Ds;
    }
}