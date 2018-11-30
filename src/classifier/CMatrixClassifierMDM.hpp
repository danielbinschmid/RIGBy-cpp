#pragma once
#include "IMatrixClassifier.hpp"
#include "utils/Metrics.hpp"

class CMatrixClassifierMDM : public IMatrixClassifier
{
public:
	std::vector<Eigen::MatrixXd> m_Means;
	EMetrics m_Metric = Metric_Riemann;

	CMatrixClassifierMDM();
	explicit CMatrixClassifierMDM(size_t classcount, EMetrics metric);
	~CMatrixClassifierMDM() override = default;

	void setClassCount(size_t classcount) override;

	bool train(const std::vector<std::vector<Eigen::MatrixXd>>& datasets) override;
	bool classify(const Eigen::MatrixXd& sample, uint32_t& classid) override;
	bool classify(const Eigen::MatrixXd& sample, uint32_t& classid, std::vector<double>& distance, std::vector<double>& probability) override;

	bool operator==(const CMatrixClassifierMDM& obj) const;
	bool operator!=(const CMatrixClassifierMDM& obj) const;
	friend std::ostream& operator <<(std::ostream& os, const CMatrixClassifierMDM& obj);
};
