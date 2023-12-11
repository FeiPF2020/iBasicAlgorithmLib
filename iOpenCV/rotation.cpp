//#include <opencv2/opencv.hpp>
//#include <cmath>
//
//cv::Mat rotateQuadrilateral(double angle, const cv::Point2f& center) {
//    cv::Mat image(1000, 1000, CV_8UC3, cv::Scalar(255, 255, 255));  // 创建白色图像
//
//
//
//    cv::circle(image,center,10,(0,0,0),10);
//
//
//    // 定义原始四边形的四个顶点
//    cv::Point2f vertices[4];
//    vertices[0] = cv::Point2f(400, 400);
//    vertices[1] = cv::Point2f(600, 400);
//    vertices[2] = cv::Point2f(700, 600);
//    vertices[3] = cv::Point2f(300, 600);
//
//    // 计算旋转后的顶点位置
//    double radian = angle * CV_PI / 180.0;  // 角度转弧度
//    cv::Point2f rotatedVertices[4];
//    for (int i = 0; i < 4; ++i) {
//        double x = vertices[i].x - center.x;
//        double y = vertices[i].y - center.y;
//        rotatedVertices[i].x = x * cos(radian) - y * sin(radian) + center.x;
//        rotatedVertices[i].y = x * sin(radian) + y * cos(radian) + center.y;
//    }
//
//    // 绘制旋转后的四边形
//    cv::line(image, rotatedVertices[0], rotatedVertices[1], cv::Scalar(0, 0, 255), 2);
//    cv::line(image, rotatedVertices[1], rotatedVertices[2], cv::Scalar(0, 0, 255), 2);
//    cv::line(image, rotatedVertices[2], rotatedVertices[3], cv::Scalar(0, 0, 255), 2);
//    cv::line(image, rotatedVertices[3], rotatedVertices[0], cv::Scalar(0, 0, 255), 2);
//
//    return image;
//}
//
//int main() {
//    double angle = 100.0;  // 旋转角度
//    cv::Point2f center(500, 500);  // 旋转中心点
//
////    cv::Mat rotatedQuadrilateral = rotateQuadrilateral(angle , center);
//
//    // 显示旋转后的四边形图像
//    for(int i = 0;i<180;){
//        cv::Mat rotatedQuadrilateral = rotateQuadrilateral(i, center);
//        cv::imshow("Rotated Quadrilateral", rotatedQuadrilateral);
//        cv::waitKey(1000/2);
//        i+=10;
//    }
//
//
//    return 0;
//}

#include <opencv2/opencv.hpp>
#include <cmath>


cv::Point2f vertices_points[4];
void draw_agent(cv::Mat& image, cv::Point point){
    // 定义三角形的参数
    int size = 50;  // 三角形的大小
    // 计算三角形的顶点坐标
    cv::Point top(point.x, point.y + size / 2);
    cv::Point bottom_left(point.x - size / 2, point.y - size / 2);
    cv::Point bottom_right(point.x + size / 2, point.y - size / 2);

    // 定义三角形的顶点数组
    std::vector<cv::Point> triangle_points = {top, bottom_left,point, bottom_right};
    vertices_points[0] = triangle_points[0];
    vertices_points[1] = triangle_points[1];
    vertices_points[2] = triangle_points[2];
    vertices_points[3] = triangle_points[3];

    // 绘制三角形轮廓
    cv::line(image, top, bottom_left, cv::Scalar(255, 0, 0), 2);
    cv::line(image, bottom_right, top, cv::Scalar(255, 0, 0), 2);
    cv::line(image, bottom_left,point, cv::Scalar(255, 0, 0), 2);
    cv::line(image, bottom_right,point, cv::Scalar(255, 0, 0), 2);

    // 填充三角形内部
    cv::fillPoly(image, std::vector<std::vector<cv::Point>>{triangle_points}, cv::Scalar(255, 0, 0));
}


double yaw_body = 0;
void body_yaw(cv::Mat image, double yaw, const cv::Point2f& center, const cv::Point2f vertices[4]){
    // 计算旋转后的顶点位置
    double radian = yaw * CV_PI / 180.0;  // 角度转弧度
    cv::Point2f rotatedVertices[4];
    for (int i = 0; i < 4; ++i) {
        double x = vertices[i].x - center.x;
        double y = vertices[i].y - center.y;
        rotatedVertices[i].x = x * cos(radian) - y * sin(radian) + center.x;
        rotatedVertices[i].y = x * sin(radian) + y * cos(radian) + center.y;
    }
    // 绘制旋转后的四边形
    cv::line(image, rotatedVertices[0], rotatedVertices[1], cv::Scalar(0, 0, 255), 2);
    cv::line(image, rotatedVertices[1], rotatedVertices[2], cv::Scalar(0, 0, 255), 2);
    cv::line(image, rotatedVertices[2], rotatedVertices[3], cv::Scalar(0, 0, 255), 2);
    cv::line(image, rotatedVertices[3], rotatedVertices[0], cv::Scalar(0, 0, 255), 2);
}


int main() {
    double angle = 45.0;  // 旋转角度
    cv::Point2f center(500, 500);  // 旋转中心点
    cv::Point2f vertices[4];  // 四边形的四个顶点
    vertices[0] = cv::Point2f(400, 400);
    vertices[1] = cv::Point2f(600, 400);
    vertices[2] = cv::Point2f(700, 600);
    vertices[3] = cv::Point2f(300, 600);

    cv::Mat image(1000, 1000, CV_8UC3, cv::Scalar(255, 255, 255));

        // 显示旋转后的四边形图像
    for(int i = 0;i<180;){

        draw_agent(image,center);
        body_yaw(image,i,center, vertices_points);
        cv::Mat rotatedQuadrilateral = rotateQuadrilateral(i, center);
        cv::imshow("Rotated Quadrilateral", rotatedQuadrilateral);
        cv::waitKey(1000/4);
        i+=10;
    }

    return 0;
}