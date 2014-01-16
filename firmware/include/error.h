/*
 * Copyright (C) 2014 Hauke Petersen <mail@haukepetersen.de>
 *
 * This file is subject to the terms and conditions of the GPLv2 License. 
 * See the file LICENSE in the top level directory for more details.
 */

/**
 * @ingroup     UNDEF
 * @{
 * 
 * @file        error.h
 * @brief       Low-level library error handling
 *
 * @author      Hauke Petersen <mail@haukepetersen.de>
 */

#ifndef __ERROR_H
#define __ERROR_H

void error(char *dev, uint32_t code)
{
    while(1);               // TODO do something smarter here
}

#endif /* __ERROR_H */
/** @} */