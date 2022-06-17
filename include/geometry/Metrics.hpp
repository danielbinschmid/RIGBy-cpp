///-------------------------------------------------------------------------------------------------
/// 
/// \file Metrics.hpp
/// \brief All Metrics.
/// \author Thibaut Monseigne (Inria).
/// \version 1.0.
/// \date 26/10/2018.
/// \copyright <a href="https://choosealicense.com/licenses/agpl-3.0/">GNU Affero General Public License v3.0</a>.
/// \remarks 
/// - List of Metrics inspired by the work of Alexandre Barachant : <a href="https://github.com/alexandrebarachant/pyRiemann">pyRiemann</a> (<a href="https://github.com/alexandrebarachant/pyRiemann/blob/master/LICENSE">License</a>).
/// 
///-------------------------------------------------------------------------------------------------

#pragma once
#include <string>

namespace Geometry {

/// <summary>	Enumeration of metrics. Inspired by the work of Alexandre Barachant : <a href="https://github.com/alexandrebarachant/pyRiemann">pyRiemann</a>. </summary>
enum class EMetric
{
	Riemann,		///< The Riemannian Metric.
	Euclidian,		///< The Euclidian Metric.
	LogEuclidian,	///< The Log Euclidian Metric.
	LogDet,			///< The Log Determinant Metric.
	Kullback,		///< The Kullback Metric.
	ALE,			///< The AJD-based log-Euclidean (ALE) Metric.
	Harmonic,		///< The Harmonic Metric.
	Wasserstein,	///< The Wasserstein Metric.
	Identity		///< The Identity Metric.
};

/// <summary>	Convert metric to string. </summary>
/// <param name="metric">	The metric. </param>
/// <returns>	<c>std::string</c> </returns>
inline std::string toString(const EMetric metric)
{
	switch (metric)
	{
		case EMetric::Riemann: return "riemann";
		case EMetric::Euclidian: return "euclidian";
		case EMetric::LogEuclidian: return "log_euclidian";
		case EMetric::LogDet: return "log_determinant";
		case EMetric::Kullback: return "kullback";
		case EMetric::ALE: return "ajd_based_log_euclidean";
		case EMetric::Harmonic: return "harmonic";
		case EMetric::Wasserstein: return "wasserstein";
		case EMetric::Identity: return "identity";
	}
	return "invalid_metric";
}

/// <summary>	Convert string to metric. </summary>
/// <param name="metric">	The metric. </param>
/// <returns>	<see cref="EMetric"/> </returns>
inline EMetric StringToMetric(const std::string& metric)
{
	if (metric == "riemann") { return EMetric::Riemann; }
	if (metric == "euclidian") { return EMetric::Euclidian; }
	if (metric == "log_euclidian") { return EMetric::LogEuclidian; }
	if (metric == "log_determinant") { return EMetric::LogDet; }
	if (metric == "kullback") { return EMetric::Kullback; }
	if (metric == "ajd_based_log_euclidean") { return EMetric::ALE; }
	if (metric == "harmonic") { return EMetric::Harmonic; }
	if (metric == "wasserstein") { return EMetric::Wasserstein; }
	return EMetric::Identity;
}

}  // namespace Geometry
