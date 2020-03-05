function popMenu(objId, objId1) {
    var obj = document.getElementById(objId);
    var obj1 = document.getElementById(objId1);
    if (obj.style.display == 'none') {
        {
            obj.style.display = 'block';
            obj1.style.backgroundColor = "#12387d";
        }
    } else {
        {
            obj.style.display = 'none';
            obj1.style.backgroundColor = "#224e9f";
        }
    }
}
function pointon(objId, objId1) {
    var obj = document.getElementById(objId);
    var obj1 = document.getElementById(objId1);
    if (obj.style.display == 'none') {
        {
            obj.style.display = 'block';
            obj1.style.backgroundColor = "#12387d";
        }
    }
}
function selectTag(showContent, selfObj) {
    var tag = document.getElementById("choice").getElementsByTagName("div");
    var taglength = tag.length;
    for (i = 0; i < taglength; i++) {
        tag[i].className = "Tag";
    }
    selfObj.parentNode.className = "selectTags";
    for (i = 0; j = document.getElementById("Content" + i) ; i++) {
        j.style.display = "none";
    }
    document.getElementById(showContent).style.display = "block";
}
function Refresh() {
    var num = Math.random();
    var VerifyCode = document.getElementById("VerfyCode");
    VerifyCode.src = "../VerifyCode.aspx?" + num;
}


//////////////////////////////////////////////////////////////
var oCalendarEn = new PopupCalendar("oCalendarEn"); //初始化控件时,请给出实例名称如:oCalendarEn
oCalendarEn.Init();

var oCalendarChs = new PopupCalendar("oCalendarChs"); //初始化控件时,请给出实例名称:oCalendarChs
oCalendarChs.weekDaySting = new Array("日", "一", "二", "三", "四", "五", "六");
oCalendarChs.monthSting = new Array("一月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月");
oCalendarChs.oBtnTodayTitle = "今天";
oCalendarChs.oBtnCancelTitle = "取消";
oCalendarChs.Init();
function checkform(myform) {
    if (myform.起始日期.value == '') {
        alert("起始日期不能为空!");
        myform.起始日期.focus();
        return false;
    }
    if (myform.结束日期.value == '') {
        alert("结束日期不能为空!");
        myform.结束日期.focus();
        return false;
    }
}
function PopupCalendar(InstanceName) {
    ///Global Tag
    this.instanceName = InstanceName;
    ///Properties
    this.separator = "-"
    this.oBtnTodayTitle = "Today"
    this.oBtnCancelTitle = "Cancel"
    this.weekDaySting = new Array("S", "M", "T", "W", "T", "F", "S");
    this.monthSting = new Array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");
    this.Width = 200;
    this.currDate = new Date();
    this.today = new Date();
    this.startYear = 2010;
    this.endYear = 2020;
    ///Css
    this.normalfontColor = "#666666";
    this.selectedfontColor = "red";
    this.divBorderCss = "1px solid #BCD0DE";
    this.titleTableBgColor = "#98B8CD";
    this.tableBorderColor = "#CCCCCC"
    ///Method
    this.Init = CalendarInit;
    this.Fill = CalendarFill;
    this.Refresh = CalendarRefresh;
    this.Restore = CalendarRestore;
    ///HTMLObject
    this.oTaget = null;
    this.oPreviousCell = null;
    this.sDIVID = InstanceName + "_Div";
    this.sTABLEID = InstanceName + "_Table";
    this.sMONTHID = InstanceName + "_Month";
    this.sYEARID = InstanceName + "_Year";
    this.sTODAYBTNID = InstanceName + "_TODAYBTN";

}
function CalendarInit()    ///Create panel
{
    var sMonth, sYear
    sMonth = this.currDate.getMonth();
    sYear = this.currDate.getFullYear();
    htmlAll = "<iframe style='position:absolute;z-index:9;width:expression(this.nextSibling.offsetWidth);height:expression(this.nextSibling.offsetHeight);top:expression(this.nextSibling.offsetTop);left:expression(this.nextSibling.offsetLeft);' frameborder='0' ></iframe><div id='" + this.sDIVID + "' style='display:none;position:absolute;width:" + this.Width + "px;border:" + this.divBorderCss + ";padding:2px;background-color:#FFFFFF;z-index:10;'>";
    htmlAll += "<div align='center'>";
    /// Month
    htmloMonth = "<select id='" + this.sMONTHID + "' onchange=CalendarMonthChange(" + this.instanceName + ") style='width:50%'>";
    for (i = 0; i < 12; i++) {
        htmloMonth += "<option value='" + i + "'>" + this.monthSting[i] + "</option>";
    }
    htmloMonth += "</select>";
    /// Year
    htmloYear = "<select id='" + this.sYEARID + "' onchange=CalendarYearChange(" + this.instanceName + ") style='width:50%'>";
    for (i = this.startYear; i <= this.endYear; i++) {
        htmloYear += "<option value='" + i + "'>" + i + "</option>";
    }
    htmloYear += "</select></div>";
    /// Day
    htmloDayTable = "<table id='" + this.sTABLEID + "' width='100%' border=0 cellpadding=0 cellspacing=1 bgcolor='" + this.tableBorderColor + "'>";
    htmloDayTable += "<tbody bgcolor='#ffffff'style='font-size:13px'>";
    for (i = 0; i <= 6; i++) {
        if (i == 0)
            htmloDayTable += "<tr bgcolor='" + this.titleTableBgColor + "'>";
        else
            htmloDayTable += "<tr>";
        for (j = 0; j < 7; j++) {
            if (i == 0) {
                htmloDayTable += "<td height='20' align='center' valign='middle' style='cursor:hand'>";
                htmloDayTable += this.weekDaySting[j] + "</td>"
            }
            else {
                htmloDayTable += "<td height='20' align='center' valign='middle' style='cursor:hand'";
                htmloDayTable += " onmouseover=CalendarCellsMsOver(" + this.instanceName + ")";
                htmloDayTable += " onmouseout=CalendarCellsMsOut(" + this.instanceName + ")";
                htmloDayTable += " onclick=CalendarCellsClick(this," + this.instanceName + ")>";
                htmloDayTable += "&nbsp;</td>"
            }
        }
        htmloDayTable += "</tr>";
    }
    htmloDayTable += "</tbody></table>";
    /// Today Button
    htmloButton = "<div align='center' style='padding:3px'>"
    htmloButton += "<button id='" + this.sTODAYBTNID + "' style='width:40%;border:1px solid #BCD0DE;background-color:#eeeeee;cursor:hand'"
    htmloButton += " onclick=CalendarTodayClick(" + this.instanceName + ")>" + this.oBtnTodayTitle + "</button>&nbsp;"
    htmloButton += "<button style='width:40%;border:1px solid #BCD0DE;background-color:#eeeeee;cursor:hand'"
    htmloButton += " onclick=CalendarCancel(" + this.instanceName + ")>" + this.oBtnCancelTitle + "</button> "
    htmloButton += "</div>"
    /// All
    htmlAll = htmlAll + htmloMonth + htmloYear + htmloDayTable + htmloButton + "</div>";
    document.write(htmlAll);
    this.Fill();
}
function CalendarFill()   ///
{
    var sMonth, sYear, sWeekDay, sToday, oTable, currRow, MaxDay, iDaySn, sIndex, rowIndex, cellIndex, oSelectMonth, oSelectYear
    sMonth = this.currDate.getMonth();
    sYear = this.currDate.getFullYear();
    sWeekDay = (new Date(sYear, sMonth, 1)).getDay();//问题归结
    sToday = this.currDate.getDate();
    iDaySn = 1
    oTable = document.all[this.sTABLEID];
    currRow = oTable.rows[1];
    MaxDay = CalendarGetMaxDay(sYear, sMonth);

    oSelectMonth = document.all[this.sMONTHID]
    oSelectMonth.selectedIndex = sMonth;
    oSelectYear = document.all[this.sYEARID]
    for (i = 0; i < oSelectYear.length; i++) {
        if (parseInt(oSelectYear.options[i].value) == sYear) oSelectYear.selectedIndex = i;
    }
    ////
    for (rowIndex = 1; rowIndex <= 6; rowIndex++) {
        if (iDaySn > MaxDay) break;
        currRow = oTable.rows[rowIndex];
        cellIndex = 0;
        if (rowIndex == 1) cellIndex = sWeekDay;
        for (; cellIndex < currRow.cells.length; cellIndex++) {
            if (iDaySn == sToday) {
                currRow.cells[cellIndex].innerHTML = "<font color='" + this.selectedfontColor + "'><i><b>" + iDaySn + "</b></i></font>";
                this.oPreviousCell = currRow.cells[cellIndex];
            }
            else {
                currRow.cells[cellIndex].innerHTML = iDaySn;
                currRow.cells[cellIndex].style.color = this.normalfontColor;
            }
            CalendarCellSetCss(0, currRow.cells[cellIndex]);
            iDaySn++;
            if (iDaySn > MaxDay) break;
        }
    }
}
function CalendarRestore()     /// Clear Data
{
    var i, j, oTable
    oTable = document.all[this.sTABLEID]
    for (i = 1; i < oTable.rows.length; i++) {
        for (j = 0; j < oTable.rows[i].cells.length; j++) {
            CalendarCellSetCss(0, oTable.rows[i].cells[j]);
            oTable.rows[i].cells[j].innerHTML = "&nbsp;";
        }
    }
}
function CalendarRefresh(newDate)     ///
{
    this.currDate = newDate;
    this.Restore();
    this.Fill();
}
function CalendarCellsMsOver(oInstance)    /// Cell MouseOver
{
    var myCell = event.srcElement;
    CalendarCellSetCss(0, oInstance.oPreviousCell);
    if (myCell) {
        CalendarCellSetCss(1, myCell);
        oInstance.oPreviousCell = myCell;
    }
}
function CalendarCellsMsOut(oInstance)    ////// Cell MouseOut
{
    var myCell = event.srcElement;
    CalendarCellSetCss(0, myCell);
}
function CalendarYearChange(oInstance)    /// Year Change
{
    var sDay, sMonth, sYear, newDate
    sDay = oInstance.currDate.getDate();
    sMonth = oInstance.currDate.getMonth();
    sYear = document.all[oInstance.sYEARID].value
    newDate = new Date(sYear, sMonth, sDay);
    oInstance.Refresh(newDate);
}
function CalendarMonthChange(oInstance)    /// Month Change
{
    var sDay, sMonth, sYear, newDate
    sDay = oInstance.currDate.getDate();
    sMonth = document.all[oInstance.sMONTHID].value
    sYear = oInstance.currDate.getFullYear();
    newDate = new Date(sYear, sMonth, sDay);
    oInstance.Refresh(newDate);
}
function CalendarCellsClick(oCell, oInstance) {
    var sDay, sMonth, sYear, newDate
    sYear = oInstance.currDate.getFullYear();
    sMonth = oInstance.currDate.getMonth();
    sDay = oInstance.currDate.getDate();
    if (oCell.innerText != " ") {
        sDay = parseInt(oCell.innerText);
        if (sDay != oInstance.currDate.getDate()) {
            newDate = new Date(sYear, sMonth, sDay);
            oInstance.Refresh(newDate);
        }
    }
    sDateString = sYear + oInstance.separator + CalendarDblNum(sMonth + 1) + oInstance.separator + CalendarDblNum(sDay); ///return sDateString
    if (oInstance.oTaget.tagName.toLowerCase() == "input") oInstance.oTaget.value = sDateString;
    CalendarCancel(oInstance);
    return sDateString;
}
function CalendarTodayClick(oInstance)    /// "Today" button Change
{
    oInstance.Refresh(new Date());
}
function getDateString(oInputSrc, oInstance) {
    if (oInputSrc && oInstance) {
        var CalendarDiv = document.all[oInstance.sDIVID];
        oInstance.oTaget = oInputSrc;
        CalendarDiv.style.pixelLeft = CalendargetPos(oInputSrc, "Left");
        CalendarDiv.style.pixelTop = CalendargetPos(oInputSrc, "Top") + oInputSrc.offsetHeight;
        CalendarDiv.style.display = (CalendarDiv.style.display == "none") ? "" : "none";
    }
}
function CalendarCellSetCss(sMode, oCell)   /// Set Cell Css
{
    // sMode
    // 0: OnMouserOut 1: OnMouseOver 
    if (sMode) {
        oCell.style.border = "1px solid #5589AA";
        oCell.style.backgroundColor = "#BCD0DE";
    }
    else {
        oCell.style.border = "1px solid #FFFFFF";
        oCell.style.backgroundColor = "#FFFFFF";
    }
}
function CalendarGetMaxDay(nowYear, nowMonth)   /// Get MaxDay of current month
{
    var nextMonth, nextYear, currDate, nextDate, theMaxDay
    nextMonth = nowMonth + 1;
    if (nextMonth > 11) {
        nextYear = nowYear + 1;
        nextMonth = 0;
    }
    else {
        nextYear = nowYear;
    }
    currDate = new Date(nowYear, nowMonth, 1);
    nextDate = new Date(nextYear, nextMonth, 1);
    theMaxDay = (nextDate - currDate) / (24 * 60 * 60 * 1000);
    return theMaxDay;
}
function CalendargetPos(el, ePro)    /// Get Absolute Position
{
    var ePos = 0;
    while (el != null) {
        ePos += el["offset" + ePro];
        el = el.offsetParent;
    }
    return ePos;
}
function CalendarDblNum(num) {
    if (num < 10)
        return "0" + num;
    else
        return num;
}
function CalendarCancel(oInstance)   ///Cancel
{
    var CalendarDiv = document.all[oInstance.sDIVID];
    CalendarDiv.style.display = "none";
}
function MM_goToURL() { //v3.0
    var i, args = MM_goToURL.arguments; document.MM_returnValue = false;
    for (i = 0; i < (args.length - 1) ; i += 2) eval(args[i] + ".location='" + args[i + 1] + "'");
}
function MM_openBrWindow(theURL, winName, features) { //v2.0
    window.open(theURL, winName, features);
}
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
(function ($) {
    $.fn.UISlide = function (options) {
        var defaults = {
            playTime: 2500,
            duration: 800,
            direction: 'left',
            easing: 'easeInOutQuad',
            clickEasing: 'easeOutCubic'
        };
        var opts = $.extend({}, defaults, options);
        var slide = {

            play: function (opts, me) {
                var that = this,
                isPlay;
                that.me = me;
                that.picList = me.find('ul');
                that.title = me.find('div').find('a');
                that.oNum = me.find('dl');
                that.lis = that.picList.find('li');
                that.size = that.lis.length;
                that.lisWidth = that.lis.width();
                that.isPlay = isPlay;
                for (var p in opts) {
                    that[p] = opts[p];
                }
                that.setNums().setTitle();
                if (that.size > 1) {
                    that.autoPlay().slideEvent();
                }
            },

            setNums: function () {
                var that = this,
                links,
                me = that.me,
                size = that.size,
                oNum = that.oNum,
                arrTemp = [];
                links = that.picList.find('a').first();
                that.title.html(links[0].title).attr('href', links[0].href);
                for (var i = 1; i <= size; i++) {
                    arrTemp.push('<dd>' + i + '</dd>');
                }
                oNum.append(arrTemp.join(''));
                that.slideNum = oNum.find('dd');
                that.numWidth = (that.slideNum.width() + parseInt(that.slideNum.css('margin-right')) + 2) * size + 1;
                that.setTitle();
                return that;
            },

            autoPlay: function () {
                var that = this,
                activePos,
                direction = that.direction,
                picList = that.picList,
                slideNum = that.slideNum,
                playTime = that.playTime;
                that.isPlay = setInterval(function () {
                    activePos = that.oNum.find('.active').index();
                    if (direction == 'left') {
                        if (activePos == (that.size - 1)) {
                            direction = 'right';
                            activePos--;
                        } else {
                            activePos++;
                        }
                    } else {
                        if (activePos == 0) {
                            direction = 'left';
                            activePos++;
                        } else {
                            activePos--;
                        }
                    }
                    picList.stop().animate({ 'margin-left': 0 - activePos * (that.lisWidth + 3) }, { duration: that.duration, easing: that.easing });
                    slideNum.removeClass('active').eq(activePos).addClass('active');
                    var links = picList.find('a').eq(activePos);
                    that.title.html(links[0].title).attr('href', links[0].href);
                }, playTime);
                return that;
            },
            setTitle: function () {
                var that = this;
                that.oNum.width(that.numWidth + 2);
                that.picList.width((that.lisWidth + 3) * that.size);
                that.slideNum.first().addClass('active');
                return that;
            },
            slideEvent: function () {
                var that = this,
                slideNum = that.slideNum;
                slideNum.click(function () {
                    var thisNum = $(this).index();
                    that.picList.stop().animate({ "margin-left": 0 - thisNum * (that.lisWidth + 3) }, { duration: that.duration, easing: that.clickEasing });
                    slideNum.removeClass('active').eq(thisNum).addClass('active');
                    var links = that.picList.find('a').eq(thisNum);
                    that.title.html(links[0].title).attr('href', links[0].href);
                });
                that.me.hover(function () {
                    clearInterval(that.isPlay);
                }, function () {
                    that.autoPlay();
                })
                return that;
            }
        };
        return this.each(function () {
            slide.play(opts, $(this));
        });
    }
})(jQuery);
/////////////////////////////////////////////////////////