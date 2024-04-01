package com.suyyyus.web.servlet.cookie;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLDecoder;
import java.net.URLEncoder;

@WebServlet("/bServlet")
public class bServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        doGet(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //1.获取cookie
        Cookie[] cookies = request.getCookies();
        //2.遍历cookie
        for (Cookie cookie : cookies) {
            if("username".equals(cookie.getName())){
                String value = cookie.getValue();
                value = URLDecoder.decode(value,"UTF-8");
                System.out.println(cookie.getName() + "->" + value);
            }
        }

    }
}
