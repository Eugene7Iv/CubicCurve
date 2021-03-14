#pragma once
#include "Graph.h"
#include "Cubic.h"
class CubicGraph :
	public Graph
{
public:
	CubicGraph(QChart* chart);
	~CubicGraph();

	void updateK(double k);
	void updateV(double v);
	void updateQ(double q);

	void draw() override;

private:
	inline Cubic* cubic();
};

