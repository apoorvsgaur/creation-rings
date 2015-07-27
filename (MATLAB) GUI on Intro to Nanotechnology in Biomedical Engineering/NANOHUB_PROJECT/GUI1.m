%Designed by Junpeng Qiu
function varargout = GUI1(varargin)
% GUI1 MATLAB code for GUI1.fig
%      GUI1, by itself, creates a new GUI1 or raises the existing
%      singleton*.
%
%      H = GUI1 returns the handle to a new GUI1 or the handle to
%      the existing singleton*.
%
%      GUI1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI1.M with the given input arguments.
%
%      GUI1('Property','Value',...) creates a new GUI1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI1

% Last Modified by GUIDE v2.5 11-Apr-2013 21:57:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI1_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI1 is made visible.
function GUI1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI1 (see VARARGIN)

% Choose default command line output for GUI1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
axes(handles.picture)
imshow('GUI1_plz.jpg')

axes(handles.legend);
imshow('GUI1_blank.jpg');

% UIWAIT makes GUI1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
nanohubGUI_sec008_team24
close('GUI1')

% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
overviewGUI_sec008_team24

% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
GUI2

% --- Executes on selection change in popDist.
function popDist_Callback(hObject, eventdata, handles)
% hObject    handle to popDist (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
select = get(hObject,'Value');%see what the users select
switch select
    case 1 %no select
        axes(handles.picture);
        imshow('GUI1_plz.jpg');
        set(handles.description,'String',' ')
        axes(handles.legend);
        imshow('GUI1_blank.jpg');
    case 2 %1 km
        axes(handles.picture);
        imshow('GUI1_1km.jpg');
        set(handles.description,'String','1 km (1000 m) is the distance from Purdue Armstrong Hall to Wildcat Creek Park.')
        axes(handles.legend);
        imshow('GUI1_legend.jpg');
    case 3 %1 m
        axes(handles.picture);
        imshow('GUI1_1m.jpg');
        set(handles.description,'String','1 m is approximately the length of the pizza shown on the left picture.')
        axes(handles.legend);
        imshow('GUI1_blank.jpg');
    case 4 %1 mm
        axes(handles.picture);
        imshow('GUI1_1mm.jpg');
        set(handles.description,'String','1 mm (10e-3 m) is approximately the ''diameter'' of the sharp part of the pencil.')
        axes(handles.legend);
        imshow('GUI1_blank.jpg');
    case 5 %1 um
        axes(handles.picture);
        imshow('GUI1_1um.jpg');
        set(handles.description,'String','1 um (10e-6 m) is usually used to indicate the size of a single bacterial or cell.')
        axes(handles.legend);
        imshow('GUI1_blank.jpg');
    case 6 %1 nm
        axes(handles.picture);
        imshow('GUI1_1nm.jpg');
        set(handles.description,'String','1 nm (10e-9 m) is roughly the length of a single sucrose molecule.')
        axes(handles.legend);
        imshow('GUI1_blank.jpg');
end
% Hints: contents = cellstr(get(hObject,'String')) returns popDist contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popDist


% --- Executes during object creation, after setting all properties.
function popDist_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popDist (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
