package com.suyyyus.web.servlet;

import com.alibaba.fastjson.JSON;
import com.suyyyus.Dao.AdminDao;
import com.suyyyus.Dao.impl.AdminDaoImpl;
import com.suyyyus.pojo.Admin;
import com.suyyyus.service.AdminService;
import com.suyyyus.service.impl.AdminServiceImpl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.util.List;

@WebServlet("/Admin/*")
public class AdminServlet extends BaseServlet{
    private AdminService adminService = new AdminServiceImpl();
    private AdminDao adminDao = new AdminDaoImpl();

    /**
     * 登录
     * @param req
     * @param resp
     * @throws Exception
     */
    public void adminLogin(HttpServletRequest req, HttpServletResponse resp) throws Exception {


        BufferedReader reader = req.getReader();
        String id = reader.readLine();
        Admin admin =JSON.parseObject(id,Admin.class);

        if(admin.getAdminname().isEmpty() || admin.getPassword().isEmpty()){
            resp.getWriter().write("null");
            return;
        }else {
            //设置编码格式
            resp.setContentType("text/html;charset=utf-8");
            //判断管理员名
            boolean b = adminService.checkAdmin(admin.getAdminname(),admin.getPassword());
            //boolean b = adminService.checkByAdminname(adminName);
            //判断密码
            //boolean b1 = adminService.checkByPassword(admin.getPassword());
            //boolean b1 = adminService.checkByPassword(password);
            //都正确才能成功登录
            if(b){
                resp.getWriter().write("success");
                System.out.println("success");
            }else {
                resp.getWriter().write("failed");
                System.out.println("failed");
            }
            resp.setStatus(HttpServletResponse.SC_OK);
            System.out.println("Response status code: " + resp.getStatus());
        }


    }


    /**
     * 查询所有管理员信息
     * @param req
     * @param resp
     * @throws Exception
     */
    public void selectAll(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        //1.调用查询

        List<Admin> adminList = adminService.queryAll();

        //2.转为JSON
        String jsonString = JSON.toJSONString(adminList);

        //3.写数据
        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
        //System.out.println("User selectAll----------");
    }
}
