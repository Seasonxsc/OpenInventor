// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "Pch.h"
#include <stdio.h>
#include <tchar.h>
#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoGroup.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoSeparator.h>

// robot.cpp : 定义控制台应用程序的入口点。
//



SoSeparator *makeScene()
{
	SoSeparator* robot = new SoSeparator;
	SoSeparator* body = new SoSeparator;
	SoSeparator* head = new SoSeparator;
	SoSeparator* leftleg = new SoSeparator;
	SoSeparator* rightleg = new SoSeparator;
	SoSeparator* leg = new SoSeparator;

	//躯干 socylinder圆柱形
	SoCylinder* bodycylinder = new SoCylinder;
	bodycylinder->radius = 2.5;
	bodycylinder->height = 6;

	SoMaterial* bronze = new SoMaterial;  //设置躯干颜色材质
	bronze->ambientColor.setValue(0.33, 0.22, 0.27);
	bronze->diffuseColor.setValue(0.78, 0.57, 0.11);
	bronze->specularColor.setValue(0.99, 0.94, 0.81);
	bronze->shininess = 0.28;

	//创建机器人的基本腿群组，它由大腿、小腿、和脚构成
	SoCube* thigh = new SoCube;                          //大腿 socube方形
	thigh->width = 1.2;
	thigh->height = 2.2;
	thigh->depth = 1.1;

	SoCube* calf = new SoCube;                           //小腿
	calf->width = 1.0;
	calf->height = 2.2;
	calf->depth = 1.0;

	SoCube* foot = new SoCube;                          //脚
	foot->width = 0.8;
	foot->height = 0.8;
	foot->depth = 2.0;

	//创建机器人的头部
	SoSphere* headsphere = new SoSphere;
	SoMaterial* sliver = new SoMaterial;
	sliver->ambientColor.setValue(0.2, 0.2, 0.2);
	sliver->diffuseColor.setValue(0.6, 0.6, 0.6);
	sliver->specularColor.setValue(0.5, 0.5, 0.5);
	sliver->shininess = 0.5;

	//坐标系建立，自顶向下，方便理解坐标系，设置使所有零件接触
	SoTransform* bodytransform = new SoTransform;  //默认body坐标系与世界坐标系重合

	bodytransform->translation.setValue(0.0, 0.0, 0.0);

	SoTransform* headtransform = new SoTransform;
	headtransform->translation.setValue(0.0, 4.0, 0.0); //头部默认半径为1，躯干高为6，所以坐标系应该Y轴走4

	SoTransform* lefttransform = new SoTransform;
	lefttransform->translation.setValue(1.0, -4.1, 0.0); //因为左腿坐标系和大腿坐标系重合的，所以Y轴3+1.1 = 4.1

	SoTransform* righttransform = new SoTransform;
	righttransform->translation.setValue(-1.0, -4.1, 0.0);

	//同一行的坐标系是相对的，soseparator中
	SoTransform* thightransform = new SoTransform;
	thightransform->translation.setValue(0.0, 0.0, 0.0);  //大腿坐标系与leg的坐标系重合

	SoTransform* calfTransform = new SoTransform;          //小腿1.1+1.1
	calfTransform->translation.setValue(0.0, -2.2, 0.0);

	SoTransform* foottransform = new SoTransform;            //脚1.1+0.4
	foottransform->translation.setValue(0.0, -1.5, 0.5);

	//组建层次结构，从底向下
	leg->addChild(thightransform);
	leg->addChild(thigh);
	leg->addChild(calfTransform);
	leg->addChild(calf);
	leg->addChild(foottransform);
	leg->addChild(foot);

	leftleg->addChild(lefttransform);
	leftleg->addChild(leg);

	rightleg->addChild(righttransform);
	rightleg->addChild(leg);

	body->addChild(bodytransform);
	body->addChild(bronze);
	body->addChild(bodycylinder);
	body->addChild(leftleg);
	body->addChild(rightleg);


	head->addChild(headtransform);
	head->addChild(sliver);
	head->addChild(headsphere);

	//组装头部和身体，形成机器人
	/*SoSeparator* robot = new SoSeparator;*/
	robot->addChild(body);
	robot->addChild(head);

	return robot;

}
int _tmain(int argc, _TCHAR* argv[])
{
	HWND mywindow = SoWin::init("");
	if (mywindow = NULL)
	{
		exit(1);
	}
	SoSeparator* root = new SoSeparator;
	root->ref();
	root->addChild(makeScene());

	SoWinExaminerViewer* myviewer = new SoWinExaminerViewer(mywindow);
	myviewer->setSceneGraph(root);
	myviewer->setBackgroundColor(SbColor(0.8, 0.8, 0.8));
	myviewer->setTitle("open invenor robot");
	myviewer->show();
	myviewer->viewAll();

	SoWin::show(mywindow);
	SoWin::mainLoop();

	return 0;
}
