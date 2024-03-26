package com.suyyyus.Servlet;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Map;

@WebServlet("/req2")
public class allServlet extends HttpServlet {
    /**
     * GET方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");//解决可能中文乱码问题
        StringBuffer requestURL = req.getRequestURL();
        System.out.println(requestURL.toString());
        String method = req.getMethod();
        System.out.println("方法->" + method);
        System.out.println("{");
        String username = req.getParameter("username");

        //username = new String(username.getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8);
        System.out.println("username : " + username);

        String password = req.getParameter("password");
        //password = new String(password.getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8);
        System.out.println("password : " + password);
        System.out.println("}");
        int status = resp.getStatus();
        System.out.println("状态码->" + status);
        System.out.println("==================");
    }

    /**
     * POST方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }


    /**
     *HEAD方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doHead(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setHeader("Custom-Header", "now is doHead");
        System.out.println("HEAD request received for: " + req.getRequestURL());
        resp.setContentType("text/html;charset=utf-8");
        String method = req.getMethod();
        System.out.println("调用方法-> " + method);
        System.out.println("自定义的响应头信息: " + resp.getHeader("Custom-Header"));
        /**
         * 不会在页面显示东西
         */
        PrintWriter writer = resp.getWriter();
        writer.write("调用doHead成功");
        int status = resp.getStatus();
        System.out.println("修改前的状态码->" + status);
        System.out.println("故意修改下状态码");
        resp.setStatus(304);
        int status1 = resp.getStatus();
        System.out.println("修改后的状态码->" + status1);
        System.out.println("==================");

    }

    
    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //防止中文乱码
        req.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=utf-8");
        System.out.println("PUT request received for: " + req.getRequestURL());
        String method = req.getMethod();
        System.out.println("调用方法-> " + method);
        PrintWriter writer = resp.getWriter();

        writer.write("<h4>调用doPut成功</h4>");
        int status = resp.getStatus();
        System.out.println("状态码->" + status);
        System.out.println("==================");
    }

    /**
     *DELETE方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //防止乱码
        System.out.println("DELETE request received for: " + req.getRequestURL());
        resp.setContentType("text/html;charset=utf-8");
        String method = req.getMethod();
        System.out.println("调用方法-> " + method);
        PrintWriter writer = resp.getWriter();
        writer.write("<h2>调用doDelete成功</h2>!");
        int status = resp.getStatus();
        System.out.println("状态码->" + status);
        System.out.println("==================");
    }

    /**
     * OPTIONS方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("OPTIONS request received for: " + req.getRequestURL());
        resp.setHeader("Custom-Header", "do your Options");
        resp.setContentType("text/html;charset=utf-8");
        String method = req.getMethod();
        System.out.println("调用方法-> " + method);
        resp.getWriter().println("调用doOptions成功!");
        System.out.println("自定义的响应头信息: " + resp.getHeader("Custom-Header"));
        int status = resp.getStatus();
        System.out.println("状态码->" + status);
        System.out.println("==================");
    }

    /**
     * TRACE方法
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     * 用于浏览器的安全问题之类，不会允许使用TRACE方法
     */
    @Override
    protected void doTrace(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

    }
}
