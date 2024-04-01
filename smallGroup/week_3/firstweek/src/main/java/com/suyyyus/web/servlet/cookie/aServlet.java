package com.suyyyus.web.servlet.cookie;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLEncoder;

@WebServlet( "/aServlet")
public class aServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //存中文 转换编码方式
        String value = "张三";
        value = URLEncoder.encode(value,"UTF-8");

        //1.创建cookie对象
//        Cookie cookie = new Cookie("username", "tom");
        Cookie cookie = new Cookie("username", value);
        //设置存活时间 1天
        cookie.setMaxAge(60*60*24);
        //2.提交cookie
        response.addCookie(cookie);

    }
}
