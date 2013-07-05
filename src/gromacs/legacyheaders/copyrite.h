/*
 *
 *                This source code is part of
 *
 *                 G   R   O   M   A   C   S
 *
 *          GROningen MAchine for Chemical Simulations
 *
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 *
 * For more info, check our website at http://www.gromacs.org
 *
 * And Hey:
 * Gromacs Runs On Most of All Computer Systems
 */
#ifndef _copyrite_h
#define _copyrite_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Has to be a function, so we can get version number from autoconf */
const char *GromacsVersion(void);

/* For both bromacs() and cool_quote() you have to provide a pointer to
 * a string of reasonable length (say 256) and the string length. This
 * is necessary to make the routines threadsafe and avoid allocating
 * a new string each time. The retstring pointer will be the return value.
 */
void
bromacs(char *retstring, int retsize);

/* For cool_quote, the number of the quote used will be returned in cqnum
 * if it is non-NULL.
 */
void
cool_quote(char *retstring, int retsize, int *cqnum);

void
gmx_thanx(FILE *fp);

void
please_cite(FILE *fp, const char *key);
/* Print a message asking to cite something... */

#ifdef __cplusplus
}

namespace gmx
{

class ProgramInfo;

/*! \brief
 * Settings for printBinaryInformation().
 *
 * This class is used to specify what printBinaryInformation() prints.
 */
class BinaryInformationSettings
{
    public:
        BinaryInformationSettings();

        //! Print information about build settings.
        BinaryInformationSettings &extendedInfo(bool bEnabled)
        {
            bExtendedInfo_ = bEnabled;
            return *this;
        }
        //! Print copyright and license information.
        BinaryInformationSettings &copyright(bool bEnabled)
        {
            bCopyright_ = bEnabled;
            return *this;
        }
        BinaryInformationSettings &generatedByHeader(bool bEnabled)
        {
            bGeneratedByHeader_ = bEnabled;
            return *this;
        }
        BinaryInformationSettings &linePrefix(const char *prefix)
        {
            prefix_ = prefix;
            return *this;
        }
        BinaryInformationSettings &lineSuffix(const char *suffix)
        {
            suffix_ = suffix;
            return *this;
        }

    private:
        bool        bExtendedInfo_;
        bool        bCopyright_;
        bool        bGeneratedByHeader_;
        const char *prefix_;
        const char *suffix_;

        //! Needed to read the members without otherwise unnecessary accessors.
        friend void printBinaryInformation(FILE *fp, const ProgramInfo &programInfo,
                                           const BinaryInformationSettings &settings);
};

/*! \brief
 * Print basic information about the executable.
 *
 * \param     fp           Where to print the information to.
 * \param[in] programInfo  Program information object to use.
 */
void printBinaryInformation(FILE *fp, const ProgramInfo &programInfo);
/*! \brief
 * Print basic information about the executable with custom settings.
 *
 * \param     fp           Where to print the information to.
 * \param[in] programInfo  Program information object to use.
 * \param[in] settings     Specifies what to print.
 *
 * \see BinaryInformationSettings
 */
void printBinaryInformation(FILE *fp, const ProgramInfo &programInfo,
                            const BinaryInformationSettings &settings);

} // namespace gmx;

#endif

#endif  /* _copyright_h */
