#ifndef AWS_CRT_API_H
#define AWS_CRT_API_H
/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/common/common.h>

/* AWS_CRT_API marks a function as public */
#if defined(_WIN32)
#    define AWS_CRT_API __declspec(dllexport)
#else
#    if ((__GNUC__ >= 4) || defined(__clang__))
#        define AWS_CRT_API __attribute__((visibility("default")))
#    else
#        define AWS_CRT_API
#    endif
#endif

/* Forward declarations */
struct aws_event_loop_group;
struct aws_crt_test_struct;

/* Public function definitions */
AWS_EXTERN_C_BEGIN

/* CRT */
AWS_CRT_API void aws_crt_init(void);
AWS_CRT_API int aws_crt_test_error(int);
AWS_CRT_API struct aws_crt_test_struct *aws_crt_test_pointer_error(void);
AWS_CRT_API int aws_crt_global_thread_creator_shutdown_wait_for(uint32_t wait_timeout_in_seconds);

/* Errors */
AWS_CRT_API int aws_crt_last_error(void);
AWS_CRT_API const char *aws_crt_error_str(int);
AWS_CRT_API const char *aws_crt_error_name(int);
AWS_CRT_API const char *aws_crt_error_debug_str(int);
AWS_CRT_API void aws_crt_reset_error(void);

/* IO */
AWS_CRT_API struct aws_event_loop_group *aws_crt_event_loop_group_new(uint16_t max_threads);
AWS_CRT_API void aws_crt_event_loop_group_release(struct aws_event_loop_group *elg);

AWS_EXTERN_C_END

#endif /* AWS_CRT_API_H */
