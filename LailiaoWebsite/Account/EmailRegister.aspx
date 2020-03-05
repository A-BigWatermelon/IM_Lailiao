<%@ Page Language="C#" Title="注册" AutoEventWireup="true" CodeFile="EmailRegister.aspx.cs" Inherits="Account_Register" MasterPageFile="~/App_Master/MainPage.master" %>


<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="Head_Content">
    <link rel="stylesheet" type="text/css" href="<%=ResolveUrl("~/App_Style/Register.css")%>" />
</asp:Content>

<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="Bady_Content">
    <form id="RegisterForm" runat="server">
        <div id="content">
            <div>
                <asp:Label ID="ErrorMessage" runat="server" Visible="false" Width="580px" Style="margin-top:5px;margin-left:10px"></asp:Label>
            </div>
                        <div class="accountInfo">
                            <table class="DetailForm">
                                <tr>
                                    <td class="regtext">昵称</td>
                                    <td colspan="2">
                                        <asp:TextBox ID="Email" runat="server" CssClass="textEntry"></asp:TextBox>
                                    </td>
                                    <td>
                                        <asp:RequiredFieldValidator ID="EmailRequired" runat="server" ControlToValidate="Email"
                                            ErrorMessage="必须填写“昵称”" ToolTip="必须填写“昵称”"
                                            ValidationGroup="RegisterUserValidationGroup" CssClass="failureNotification" />
                                    </td>

                                </tr>
                                <tr>
                                    <td class="regtext">密码</td>
                                    <td colspan="2">
                                        <asp:TextBox ID="Password" runat="server" CssClass="textEntry" TextMode="Password"></asp:TextBox>
                                    </td>
                                    <td>

                                        <asp:RequiredFieldValidator ID="PasswordRequired" runat="server" ControlToValidate="Password"
                                            CssClass="failureNotification" ErrorMessage="必须填写“密码”" ToolTip="必须填写“密码”"
                                            ValidationGroup="RegisterUserValidationGroup" />
                                        <asp:RegularExpressionValidator ID="PasswordLengthRequired" runat="server" ControlToValidate="Password"
                                            CssClass="failureNotification" ErrorMessage="密码长度不应少于6个字符或多于16个字符" ToolTip="密码长度不应少于6个字符或多于16个字符"
                                            ValidationExpression="[a-zA-Z0-9-_&]{6,16}" ValidationGroup="RegisterUserValidationGroup" />

                                    </td>
                                </tr>

                                <tr>
                                    <td class="regtext">确认密码</td>
                                    <td colspan="2">
                                        <asp:TextBox ID="ConfirmPassword" runat="server" CssClass="textEntry" TextMode="Password"></asp:TextBox>
                                    </td>
                                    <td>
                                        <asp:RequiredFieldValidator ControlToValidate="ConfirmPassword" CssClass="failureNotification"
                                            ErrorMessage="必须填写“确认密码”" ID="ConfirmPasswordRequired" runat="server"
                                            ToolTip="必须填写“确认密码”" ValidationGroup="RegisterUserValidationGroup" />
                                        <asp:CompareValidator ID="PasswordCompare" runat="server" ControlToCompare="Password" ControlToValidate="ConfirmPassword"
                                            CssClass="failureNotification" ErrorMessage="“密码”和“确认密码”必须匹配"
                                            ValidationGroup="RegisterUserValidationGroup" />

                                    </td>
                                </tr>
                                <tr>
                                    <td class="regtext">验证码</td>
                                    <td>
                                        <asp:TextBox ID="VerificationCode" runat="server" CssClass="textEntry" Width="100px"></asp:TextBox></td>
                                    <td>
                                        <img id="VerfyCode" alt="点击修改" src="<%=ResolveUrl("~/VerifyCode.aspx?")%>" onclick="javascript:Refresh();" style="margin-top: 5px;" /><span class="regtext">(点击刷新)</span></td>
                                    <td>
                                        <asp:RequiredFieldValidator ControlToValidate="VerificationCode"
                                            ErrorMessage="验证码不能为空" ID="VerificationCodeRequired" runat="server"
                                            ToolTip="验证码不能为空" ValidationGroup="RegisterUserValidationGroup" CssClass="failureNotification" /></td>
                                    <td></td>
                                </tr>

                                <tr>
                                    <td colspan="4">
                                        <asp:Button ID="CreateUserButton" runat="server" CommandName="MoveNext" Text="注册帐号"
                                            ValidationGroup="RegisterUserValidationGroup" CssClass="Button" OnClick="CreateUserButton_Click" />
                                    </td>
                                </tr>
                            </table>
                        </div>
        </div>
    </form>
</asp:Content>
