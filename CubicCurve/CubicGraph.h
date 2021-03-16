#pragma once
#include "Graph.h"
#include "Cubic.h"
#include "Shared.h"
class CubicGraph :
	public Graph
{
	Q_OBJECT
public:
	CubicGraph(QChart* chart);
	~CubicGraph();

	void updateK(double k, ParamsMode mode = ParamsMode::Algebraic);
	void updateV(double v, ParamsMode mode = ParamsMode::Algebraic);
	void updateQ(double q, ParamsMode mode = ParamsMode::Algebraic);

	void draw() override;

signals:
	void k_Updated(double k);
	void v_Updated(double v);
	void q_Updated(double q);

private:
	inline Cubic* cubic();
	inline const Cubic* cubic() const;
};

