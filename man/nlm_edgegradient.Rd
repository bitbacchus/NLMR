% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/nlm_edgegradient.R
\name{nlm_edgegradient}
\alias{nlm_edgegradient}
\title{nlm_edgegradient}
\usage{
nlm_edgegradient(ncol, nrow, resolution = 1, direction = NA,
  rescale = TRUE)
}
\arguments{
\item{ncol}{[\code{numerical(1)}]\cr
Number of columns forming the raster.}

\item{nrow}{[\code{numerical(1)}]\cr
Number of rows forming the raster.}

\item{resolution}{[\code{numerical(1)}]\cr
Resolution of the raster.}

\item{direction}{[\code{numerical(1)}]\cr
Direction of the gradient (between 0 and 360 degrees), if unspecified the
direction is randomly determined.}

\item{rescale}{[\code{logical(1)}]\cr
If \code{TRUE} (default), the values are rescaled between 0-1.}
}
\value{
RasterLayer
}
\description{
Simulates an edge-gradient neutral landscape model.
}
\details{
Simulates a linear gradient orientated on a specified or random direction
that has a central peak running perpendicular to the gradient direction.
}
\examples{

# simulate random curdling
edge_gradient <- nlm_edgegradient(ncol = 100, nrow = 100, direction = 80)

\dontrun{
# visualize the NLM
rasterVis::levelplot(edge_gradient, margin = FALSE, par.settings = rasterVis::viridisTheme())
}

}
\references{
Travis, J.M.J. & Dytham, C. (2004) A method for simulating patterns of
habitat availability at static and dynamic range margins. \emph{Oikos}, 104,
410–416.
}
\seealso{
\code{\link{nlm_distancegradient}},
\code{\link{nlm_planargradient}}
}
