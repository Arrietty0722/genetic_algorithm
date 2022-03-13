#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

// 安定率マップ
void cal_M_b(
    cv::Mat &M_b,
    cv::Mat &f_t)
{
    int num_of_map_S;
    cv::Mat map_S[num_of_map_S];
    cv::Mat f_tk;
    cv::Mat f_tk_list[num_of_map_S];
    for (int num = 1; num <= num_of_map_S; num += 1)
    {
        f_tk = f_tk_list[num_of_map_S];
        cal_map_S(map_S[num_of_map_S], f_t, f_tk);
    }

    int hight;
    int width;
    for (int y = 0; y <= hight; y += 1)
    {
        for (int x = 0; x <= width; x += 1)
        {
            for (int num = 1; num <= num_of_map_S; num += 1)
            {
                M_b.at<float>(x, y) += map_S[num].at<float>(x, y)
            }
        }
    }
}

void cal_map_S(
    cv::Mat &map_S,
    cv::Mat &f_t,
    cv::Mat &f_tk)
{
    float sigma[255];

    for (int qu = 0; qu <= 255; qu += 1)
    {
        sigma[qu] = cal_sigma();
    }

    int hight;
    int width;
    int p;
    int q;
    float input_sigma;
    for (int y = 0; y <= hight; y += 1)
    {
        for (int x = 0; x <= width; x += 1)
        {
            p = f_t.at<int>(x, y);
            q = f_tk.at<int>(x, y);
            input_sigma = sigma[q];
            map_S.at<float>(x, y) = cal_value_from_G_l(p, q, input_sigma);
        }
    }
}

float cal_value_from_G_l(int p, int q, float sigma)
{
    // １次元正規分布モデルに各値を代入して、出力値を返す
    float value;
    return value
}

float cal_sigma()
{
    float sigma;
    sum_h_s = 0;
    for (int p = 0; p <= 255; p += 1)
    {
        sum_h_s += cal_h_b(f_t, f_tk, p, qu);
    }

    for (int p = 0; p <= 255; p += 1)
    {
        H_l[p] = cal_h_b(f_t, f_tk, p, qu) / sum_h_s;
    }

    sigma = fit_sigma(H_l[p]);

    return sigma
}

float fit_sigma()
{
    // 1次元正規分布をH_にフィッティングさせて、シグマを求める
    float sigma;
    return sigma
}

// 画像間共起ヒストグラム
int cal_h_b(
    cv::Mat &f_t,
    cv::Mat &f_tk,
    int p,
    int q)
{
    int h_b = 0;
    int hight;
    int width;
    for (int y = 0; y <= hight; y += 1)
    {
        for (int x = 0; x <= width; x += 1)
        {
            h_b += cal_sigma_b(f_t, f_tk, p, q, x, y);
        }
    }

    return h_b;
}

int cal_sigma_b(
    cv::Mat &f_t,
    cv::Mat &f_tk,
    int p,
    int q,
    int x,
    int y)
{
    int sigma_b = 0;
    int pix_ft_p = f_t.at<int>(cv::Point(x, y));
    int pix_ftk_q = f_tk.at<int>(cv::Point(x, y));
    if ((p == pix_ft_p) && (q == pix_ftk_q))
    {
        sigma_b = 1;
    }
    return sigma_b;
}

// 空間共起確率マップ
void cal_M_s(
    cv::Mat &M_s,
    cv::Mat &f_t,
    int d_x,
    int d_y)
{
    int sum_h_s = 0;
    cv::Mat mat_h_s;
    cal_all_h_s(
        sum_h_s,
        mat_h_s,
        f_t,
        d_x,
        d_y);

    int p;
    int q;
    for (int y = 0; y <= f_t.rows; y += 1)
    {
        for (int x = 0; x <= f_t.cols; x += 1)
        {
            if ((x + d_x > f_t.cols) | (y + d_y > f_t.rows))
            {
                M_s.at<float>(x, y) = 0;
            }
            else
            {
                p = f_t.at<int>(x, y);
                q = f_t.at<int>(x, y);
                M_s.at<float>(x, y) = mat_h_s.at<int>(p, q) / sum_h_s;
            }
        }
    }
}

void cal_all_h_s(
    int &sum_h_s,
    cv::Mat &mat_h_s,
    cv::Mat f_t,
    int d_x,
    int d_y)
{
    int h_s;
    sum_h_s = 0;
    for (int p = 0; p <= 255; p += 1)
    {
        for (int q = 0; q <= 255; q += 1)
        {
            h_s = cal_h_s(f_t, p, q, d_x, d_y);
            sum_h_s += h_s;
            mat_h_s.at<int>(p, q) = h_s;
        }
    }
}

int cal_h_s(
    cv::Mat &f_t,
    int p,
    int q,
    int d_x,
    int d_y)
{
    int h_s = 0;
    int hight;
    int width;
    for (int y = 0; y <= hight; y += 1)
    {
        for (int x = 0; x <= width; x += 1)
        {
            h_s += cal_sigma_s(f_t, p, q, x, y, d_x, d_y);
        }
    }
    return h_s;
}

int cal_sigma_s(
    cv::Mat &f_t,
    int p,
    int q,
    int x,
    int y,
    int d_x,
    int d_y)
{
    int sigma_s = 0;
    if ((x + d_x > f_t.cols) | (y + d_y > f_t.rows))
    {
        return sigma_s;
    }

    int pix_V_p = f_t.at<int>(cv::Point(x, y));
    int pix_V_q = f_t.at<int>(cv::Point(x + d_x, y + d_y));
    if ((p == pix_V_p) && (q == pix_V_q))
    {
        sigma_s = 1;
    }
    return sigma_s;
}