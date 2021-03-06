#  File src/library/base/R/paste.R
#  Part of the R package, https://www.R-project.org
#
#  Copyright (C) 1995-2012 The R Core Team
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  A copy of the GNU General Public License is available at
#  https://www.R-project.org/Licenses/

## change in R 4.0.1: do it this way to allow for calls without new arg
## to work from earlier versions of R.
paste <- function (..., sep = " ", collapse = NULL, recycle0 = FALSE)
{
    if(isTRUE(recycle0))
        .Internal(paste(list(...), sep, collapse, recycle0))
    else
        .Internal(paste(list(...), sep, collapse))
}

paste0 <- function(..., collapse = NULL, recycle0 = FALSE)
{
    if(isTRUE(recycle0))
        .Internal(paste0(list(...), collapse, recycle0))
    else
        .Internal(paste0(list(...), collapse))
}

##=== Could we extend  paste(.) to (optionally) accept a
##    2-vector for collapse ?	 With the following functionality

##- paste.extra <- function(r, collapse=c(", "," and ")) {
##-	    n <- length(r)
##-	    if(n <= 1) paste(r)
##-	    else
##-	      paste(paste(r[-n],collapse=collapse[1L]),
##-		    r[n], sep=collapse[min(2,length(collapse))])
##- }
