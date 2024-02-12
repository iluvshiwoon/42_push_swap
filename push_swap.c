/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:58:30 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/11 14:46:14 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int main(int argc, char ** argv)
{
    t_circular_double_link_list cdl_list_a;
    t_circular_double_link_list cdl_list_b; // how much can the stack handle
    t_circular_double_link_list rank_a;
    t_circular_double_link_list rank_b;

    int status;
    
    // argc = 2;
    // argv[1] = "347 2770 3130 4420 2436 1600 2415 3690 1932 1589 3704 3217 2700 2854 4898 2442 3765 1886 126 1009 1400 1958 3063 445 4321 1125 3757 2733 1161 1121 3421 4585 2750 609 4869 4713 213 960 3798 1393 3864 2852 3114 3981 3160 2689 165 636 3243 4261 2648 2940 3248 304 3370 4557 744 699 3144 4689 2553 2551 2187 1601 3127 1544 1362 2075 3814 4721 133 2999 3230 3594 3394 4252 4575 1769 3330 466 4266 808 548 1445 2407 4671 4229 3250 1933 4487 3937 3770 1722 4194 4901 1621 2546 4311 4065 1043";
    // argv[1] = "31 129 67 55 576 308 71";
    // argv [1] = "1974 200 2064 1283 3655 727 314 1899 1115 375 2095 1348 4806 789 452 3288 1775 3784 819 3973 513 3385 4921 2966 3979 2862 2015 4625 4756 3278";
    // argv[1] = "12 475 562 22 397 285 135 215 56 603 432 100 293";
    // argv[1] = "627 533 574 438 174 582 591 310 4 367 89 494 275 15 445 434 142 362 640 408";
    // argv[1] = "693 1743 699 810 2998 3831 583 2673 3361 4865 2915 4143 188 2815 395 3105 431 1794 3500 678 4830 1781 898 835 1176 4610 2046 2620 3674 4993 67 723 1482 81 4184 3350 418 3336 3219 2771 765 1423 3146 3776 804 4001 261 1770 2943 3250 1429 576 3292 3066 2421 2876 408 2260 4647 1082 4899 900 945 1296 967 4706 4298 578 270 141 3302 282 643 4828 3863 4771 4606 4769 4441 1454 1399 325 4470 4648 2206 2501 1845 1445 1854 2177 1334 1988 289 3154 2361 1550 4409 3739 2827 1370 4689 1970 568 1486 1204 369 2938 4595 4910 2169 3194 1803 2555 4229 2731 4681 2566 2288 1956 3789 1839 2007 1416 3171 2112 1791 4203 798 4219 4686 3888 463 3914 3477 4039 836 2966 3701 1696 4274 4337 2834 1893 2511 100 1116 832 3306 1672 2283 513 1680 1179 797 1359 2810 136 430 1052 3862 2853 4794 3135 1396 3887 4114 1723 2621 2706 3585 3626 7 3046 3833 1509 3670 3763 363 937 869 1779 866 1461 4808 4950 3711 2166 2568 4581 3009 2977 3489 1042 4442 3968 3333 1687 615 2150 905 3604 1347 309 3442 1985 1493 3289 3343 2696 2602 3839 2184 1315 2690 4288 2105 2211 1639 4297 2091 688 4864 2172 1012 1025 1031 307 2302 995 4117 2633 4635 1067 3960 3659 1050 908 1485 885 1037 2687 4503 1756 3134 192 2309 2908 1084 791 2782 252 4406 2637 2754 2336 2728 3047 3810 1408 4786 353 4481 4936 3813 3758 2036 3307 3358 445 442 4152 4324 3625 3639 1938 3440 2601 4718 3168 757 3133 2405 28 4096 1209 1374 849 3071 2027 2900 3335 1986 868 2572 777 3245 3230 3214 4282 2491 108 47 4814 2779 3002 499 555 3209 3791 4103 3841 425 2619 3283 2901 2530 2217 1458 3372 4422 2607 2429 4633 62 2114 1151 2805 3276 3122 1406 4968 1716 1076 1326 2781 717 3330 4277 4098 2227 846 3705 3419 1619 3622 512 3220 4106 4919 4118 2266 3922 4067 4150 3445 4759 2878 538 3700 1565 4510 3102 611 902 125 148 1669 2395 612 1404 2871 805 2760 2799 297 1960 1246 436 1308 174 2453 1455 1125 2311 4734 1811 1559 589 825 1088 888 3229 705 771 1690 4802 3411 2202 4126 674 569 496 1802 4908 16 94 3666 1500 4572 4238 1377 172 3235 2636 972 3386 4153 2368 4251 4268 4158 269 506 2208 2604 2284 1575 3759 2567 1694 3144 1263 3930 1152 683 2881 75 4230 2686 2372 2263 4027 3845 1250 2651 272 1520 1683 3297 2378 2790 1146 2916 2478 515 4589 1631 3978 4218 4604 1421 3104 2963 1657 1512 4537 4488 2814 3825 1554 2657 3527 3072 2613 198 1364 2173 4004 1338 2534 2785 102 593 4026 2345 4900 5000 2759 4663 2292 2926 3553 4555 2669 144 1595 12 72 3524 1674";
    char * s = "----------------------------\n";
    //
    cdl_init_list(&cdl_list_a);
    cdl_init_list(&cdl_list_b);
    cdl_init_list(&rank_a);
    cdl_init_list(&rank_b);

    if (argc > 1)
        status = parse_input(argc, argv, &cdl_list_a); 
    else
        return (ERROR);
    //
    if (status)
    {
        // ft_printf("%sInput\n%s", s, s);
        // print_cdl(&cdl_list_a);

        rank(&cdl_list_a, &rank_a);
        deal(&cdl_list_a, &rank_a, &cdl_list_b, &rank_b);
        sort_3(&cdl_list_a, &rank_a);
        sort(&cdl_list_a, &rank_a, &cdl_list_b, &rank_b);

        print_cdl(&rank_a);
        cdl_free_list(&cdl_list_a);
        cdl_free_list(&rank_a);
        cdl_free_list(&cdl_list_b);
        cdl_free_list(&rank_b);
    }
    return (SUCCESS);
}

void print_array(int * array, size_t size)
{
    size_t i;
    
    i = 0;
    ft_printf("\n");
    while (i < size)
    {
        ft_printf("%d\n", array[i]);
        ++i;
    }
}

void print_map(t_run * run)
{
    size_t i;
    size_t n;

    i = run->map_size;
    n = i;
    --i;
    ft_printf("\n");
    while (n)
    {
        ft_printf("%c\n", run->map[i]);
        --i;
        --n;
    }
}

void print_cdl(t_circular_double_link_list * cdl_list)
{
    t_double_link_node * cdl_node;

    if (cdl_list && cdl_list->first_node)
    {
        ft_printf("\n");
        cdl_node = cdl_list->first_node;
        do {
            ft_printf("%d\n", *((int *)cdl_node->data));
            cdl_node = cdl_node->next;
        } while (cdl_node != cdl_list->first_node);
    }
    if (cdl_list)
        ft_printf("total: %u\n", cdl_list->total);
}
